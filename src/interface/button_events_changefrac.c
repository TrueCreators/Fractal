/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_events_changefrac.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:33:26 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/30 10:17:05 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	button_set_mandelbrot(t_env *e)
{
	create_button(e, &e->button[26]);
	e->fractol = "mandelbrot";
	create_kernel(e->kernel, e);
}

void	button_set_julia(t_env *e)
{
	create_button(e, &e->button[27]);
	e->fractol = "julia";
	create_kernel(e->kernel, e);
}

void	button_set_pyramide(t_env *e)
{
	create_button(e, &e->button[28]);
	e->fractol = "pyramide";
	create_kernel(e->kernel, e);
}

void	button_set_puddle(t_env *e)
{
	create_button(e, &e->button[29]);
	e->fractol = "puddle";
	create_kernel(e->kernel, e);
}
