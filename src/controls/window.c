/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:11:56 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/30 15:15:26 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		change_window_to_be_contined(int keycode, t_env *e)
{
	if (keycode == NK_N2)
	{
		e->win->x_win = 1024;
		e->win->y_win = 768;
		e->win->n_win = "Fractol 1024x768";
	}
	if (keycode == NK_N3)
	{
		e->win->x_win = 800;
		e->win->y_win = 600;
		e->win->n_win = "Fractol 800x600";
	}
}

int				key_change_window(int keycode, t_env *e)
{
	mlx_destroy_window(e->win->mlx_ptr, e->win->win_ptr);
	mlx_destroy_image(e->win->mlx_ptr, e->img->img_ptr);
	if (keycode == NK_N0)
	{
		e->win->x_win = 2880;
		e->win->y_win = 1600;
		e->win->n_win = "Fractol 2880x1600";
	}
	if (keycode == NK_N1)
	{
		e->win->x_win = 1920;
		e->win->y_win = 1080;
		e->win->n_win = "Fractol 1920x1080";
	}
	change_window_to_be_contined(keycode, e);
	init_win_img(e);
	draw(e);
	return (0);
}

void			draw(t_env *e)
{
	mlx_clear_window(e->win->mlx_ptr, e->win->win_ptr);
	start_kernel(e->kernel, e);
	mlx_put_image_to_window(e->win->mlx_ptr, e->win->win_ptr,
	e->img->img_ptr, 0, 0);
	if (e->flag.menu_glb)
	{
		init_menu(e, e->win->x_win, e->win->y_win);
		init_menu_press(e, e->win->x_win, e->win->y_win);
		main_menu(e);
		mlx_loop_hook(e->win->mlx_ptr, animation_menu, e);
	}
	if (e->flag.helpingame)
	{
		help(e);
	}
}
