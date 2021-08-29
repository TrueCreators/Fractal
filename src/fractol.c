/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:52:49 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/30 14:50:11 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_mlx(t_env *e)
{
	e->win->mlx_ptr = mlx_init();
	e->win->x_win = 2880;
	e->win->y_win = 1600;
	e->win->n_win = "Fractol 2880x1600";
	init_win_img(e);
}

void		init_win_img(t_env *e)
{
	e->win->win_ptr = mlx_new_window(e->win->mlx_ptr, e->win->x_win,
	e->win->y_win, e->win->n_win);
	e->img->img_ptr = mlx_new_image(e->win->mlx_ptr,
	e->win->x_win, e->win->y_win);
	e->img->data = (int *)mlx_get_data_addr(e->img->img_ptr, &e->img->bpp,
	&e->img->size_line, &e->img->endian);
	mlx_hook(e->win->win_ptr, 2, 0, key_press, e);
	mlx_hook(e->win->win_ptr, 4, 0, mouse_press, e);
	mlx_hook(e->win->win_ptr, 17, 0, close_programm, NULL);
	mlx_hook(e->win->win_ptr, 6, 0, mouse_move, e);
}

static void	init_fractols(t_env *e)
{
	e->mov->zoom = 1;
	e->mov->maxiter = 75;
	e->mov->ju_cre = -0.742;
	e->mov->ju_cim = 0.227;
	e->rgb->r = 0;
	e->rgb->g = 0;
	e->rgb->b = 3;
	e->flag.menu_glb = 1;
	e->flag.menu = 1;
	e->flag.move_menu = 1;
	e->flag.background = 1;
	e->flag.change_fractol = 0;
	e->flag.settings = 0;
	e->flag.controls = 0;
	e->flag.mouse = 0;
	e->flag.helpingame = 0;
	e->flag.color = 0;
	if (ft_strcmp(e->fractol, "pyramide") == 0)
	{
		e->rgb->b = 3;
	}
}

static void	memalloc_global(t_env *e)
{
	if (!(e->win = ft_memalloc(sizeof(t_win))))
		error_exit("t_win is not allocated!");
	if (!(e->mov = ft_memalloc(sizeof(t_mov))))
		error_exit("t_win is not allocated!");
	if (!(e->img = ft_memalloc(sizeof(t_img))))
		error_exit("t_img is not allocated!");
	if (!(e->rgb = ft_memalloc(sizeof(t_rgb))))
		error_exit("t_rgb is not allocated!");
	if (!(e->kernel = ft_memalloc(sizeof(t_ker))))
		error_exit("t_ker is not allocated");
	if (!(e->button = ft_memalloc(sizeof(t_butt) * 39)))
		error_exit("t_button is not allocated");
}

void		fractol(char *fractol)
{
	t_env	*e;

	if (!(e = ft_memalloc(sizeof(t_env))))
		error_exit("t_env is not allocated!");
	e->fractol = fractol;
	memalloc_global(e);
	init_mlx(e);
	init_fractols(e);
	init_kernel(e->kernel, e);
	draw(e);
	mlx_loop(e->win->mlx_ptr);
}
