/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_menu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:11:13 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/30 15:44:36 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		anim_julia(t_env *e)
{
	e->mov->zoom = 1;
	e->mov->move_x = 0;
	if (e->mov->ju_cim >= 0.145 && e->flag.move_menu)
	{
		e->mov->ju_cre -= 0.0001;
		e->mov->ju_cim -= 0.0001;
	}
	if (e->mov->ju_cim <= 0.145)
		e->flag.move_menu = 0;
	if (e->mov->ju_cim >= 0.275)
	{
		e->mov->maxiter = 75;
		e->flag.move_menu = 1;
		e->flag.color += 2;
		color_menu(e, e->flag.color);
	}
	if (e->flag.move_menu == 0)
	{
		e->mov->ju_cre += 0.0001;
		e->mov->ju_cim += 0.0001;
	}
	draw(e);
}

static void		anim_pyramide(t_env *e)
{
	e->mov->move_x = 0.5;
	if (e->mov->zoom <= 60.0 && e->flag.move_menu)
	{
		e->mov->zoom += 0.2;
	}
	if (e->mov->zoom <= -60)
		e->flag.move_menu = 2;
	if (e->mov->zoom >= 60)
		e->flag.move_menu = 0;
	if (e->mov->zoom >= -0.2 && e->mov->zoom <= 0.2)
	{
		e->flag.color += 1;
		color_menu(e, e->flag.color);
	}
	if (e->flag.move_menu == 0)
	{
		e->mov->zoom -= 0.2;
	}
	draw(e);
}

static void		anim_mandelbrot(t_env *e)
{
	e->mov->move_x = 0;
	e->mov->zoom = 1;
	draw(e);
}

int				animation_menu(t_env *e)
{
	if (ft_strcmp(e->fractol, "julia") == 0 && e->flag.background)
		anim_julia(e);
	if (ft_strcmp(e->fractol, "pyramide") == 0 && e->flag.background)
		anim_pyramide(e);
	if (ft_strcmp(e->fractol, "mandelbrot") == 0 && e->flag.background)
		anim_mandelbrot(e);
	if (ft_strcmp(e->fractol, "puddle") == 0 && e->flag.background)
		anim_mandelbrot(e);
	if (ft_strcmp(e->fractol, "time_machine") == 0 && e->flag.background)
		anim_mandelbrot(e);
	if (ft_strcmp(e->fractol, "bracelet") == 0 && e->flag.background)
		anim_mandelbrot(e);
	if (ft_strcmp(e->fractol, "butterfly") == 0 && e->flag.background)
		anim_mandelbrot(e);
	if (ft_strcmp(e->fractol, "spider") == 0 && e->flag.background)
		anim_mandelbrot(e);
	return (0);
}
