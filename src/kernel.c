/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:22:44 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/30 15:53:31 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			set_kernel_arg(t_ker *kernel, t_env *e, int i)
{
	clSetKernelArg(kernel->kernel, ++i, sizeof(cl_mem),
	(void *)&kernel->memobj);
	clSetKernelArg(kernel->kernel, ++i, sizeof(int),
	(void *)&e->win->x_win);
	clSetKernelArg(kernel->kernel, ++i, sizeof(int),
	(void *)&e->win->y_win);
	clSetKernelArg(kernel->kernel, ++i, sizeof(double),
	(void *)&e->mov->move_x);
	clSetKernelArg(kernel->kernel, ++i, sizeof(double),
	(void *)&e->mov->move_y);
	clSetKernelArg(kernel->kernel, ++i, sizeof(double),
	(void *)&e->mov->zoom);
	clSetKernelArg(kernel->kernel, ++i, sizeof(int),
	(void *)&e->mov->maxiter);
	clSetKernelArg(kernel->kernel, ++i, sizeof(double),
	(void *)&e->mov->ju_cre);
	clSetKernelArg(kernel->kernel, ++i, sizeof(double),
	(void *)&e->mov->ju_cim);
	clSetKernelArg(kernel->kernel, ++i, sizeof(int),
	(void *)&e->rgb->r);
	clSetKernelArg(kernel->kernel, ++i, sizeof(int),
	(void *)&e->rgb->g);
	clSetKernelArg(kernel->kernel, ++i, sizeof(int),
	(void *)&e->rgb->b);
}

void			start_kernel(t_ker *kernel, t_env *e)
{
	int		i;
	size_t	global_work_size[2];

	global_work_size[0] = e->win->x_win;
	global_work_size[1] = e->win->y_win;
	i = -1;
	set_kernel_arg(kernel, e, i);
	clEnqueueNDRangeKernel(kernel->command, kernel->kernel, 2, NULL,
	global_work_size, NULL, 0, NULL, NULL);
	clEnqueueReadBuffer(kernel->command, kernel->memobj, CL_TRUE, 0,
	sizeof(int) * e->win->x_win * e->win->y_win, e->img->data, 0, NULL, NULL);
}

void			create_kernel(t_ker *kernel, t_env *e)
{
	if (kernel->kernel)
		clReleaseKernel(kernel->kernel);
	kernel->kernel = clCreateKernel(kernel->program, e->fractol, NULL);
}

void			init_kernel(t_ker *kernel, t_env *e)
{
	int		fd;
	char	*filename;
	size_t	source_size;
	char	*source_str;

	filename = "src/fractols.cl";
	clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1, &kernel->device, NULL);
	kernel->context = clCreateContext(NULL, 1, &kernel->device, 0, 0, 0);
	kernel->command = clCreateCommandQueue(kernel->context,
	kernel->device, 0, 0);
	fd = open(filename, O_RDONLY, S_IRWXU);
	source_str = ft_memalloc(MAX_SOURCE_SIZE);
	source_size = read(fd, source_str, MAX_SOURCE_SIZE);
	close(fd);
	kernel->program = clCreateProgramWithSource(kernel->context, 1,
	(const char **)&source_str, (const size_t *)&source_size, NULL);
	clBuildProgram(kernel->program, 1, &kernel->device, NULL, NULL, NULL);
	kernel->kernel = NULL;
	kernel->memobj = clCreateBuffer(kernel->context, CL_MEM_READ_ONLY,
	sizeof(int) * e->win->x_win * e->win->y_win, NULL, NULL);
	ft_memdel((void**)&source_str);
	create_kernel(kernel, e);
}
