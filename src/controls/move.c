/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 23:16:59 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/30 15:11:33 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	manipulate(int keycode, t_env *e)
{
	if (keycode == NK_PLUS)
	{
		e->mov->zoom *= 1.1;
	}
	if (keycode == NK_MINUS && e->mov->zoom >= 0.2)
	{
		e->mov->zoom /= 1.1;
	}
	if (keycode == K_PLUS)
	{
		e->mov->maxiter += 25;
	}
	if (keycode == K_MINUS && e->mov->maxiter > 75)
	{
		e->mov->maxiter -= 25;
	}
	draw(e);
	return (0);
}

int	move(int keycode, t_env *e)
{
	mlx_clear_window(e->win->mlx_ptr, e->win->win_ptr);
	if (keycode == K_W || keycode == K_UP)
	{
		e->mov->move_y -= 0.1 / e->mov->zoom;
	}
	if (keycode == K_S || keycode == K_DOWN)
	{
		e->mov->move_y += 0.1 / e->mov->zoom;
	}
	if (keycode == K_D || keycode == K_RIGHT)
	{
		e->mov->move_x += 0.1 / e->mov->zoom;
	}
	if (keycode == K_A || keycode == K_LEFT)
	{
		e->mov->move_x -= 0.1 / e->mov->zoom;
	}
	draw(e);
	return (0);
}
