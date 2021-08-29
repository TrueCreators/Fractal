/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:12:47 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/30 12:57:58 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			button_menu_canvas(int button, int x, int y, t_env *e)
{
	if (button == MK_LEFT && x >= e->win->x_win / 2 - (150 / 2) &&
	x <= e->win->x_win / 2 + (150 / 2) && y >= e->win->y_win / 2
	- (50 / 2) - 200 && y <= e->win->y_win / 2 + (50 / 2) - 200)
	{
		button_play_canvas(e);
	}
	if (button == MK_LEFT && x >= e->win->x_win / 2 - (150 / 2) &&
	x <= e->win->x_win / 2 + (150 / 2) && y >= e->win->y_win / 2 -
	(50 / 2) - 100 && y <= e->win->y_win / 2 + (50 / 2) - 100)
	{
		button_change_fractol_canvas(e);
	}
	if (button == MK_LEFT && x >= e->win->x_win / 2 - (150 / 2) &&
	x <= e->win->x_win / 2 + (150 / 2) && y >= e->win->y_win / 2 -
	(50 / 2) && y <= e->win->y_win / 2 + (50 / 2))
	{
		button_settings_e_canvas(e);
	}
	if (button == MK_LEFT && x >= e->win->x_win / 2 - (150 / 2) &&
	x <= e->win->x_win / 2 + (150 / 2) && y >= e->win->y_win / 2 -
	(50 / 2) + 100 && y <= e->win->y_win / 2 + (50 / 2) + 100)
	{
		create_button(e, &e->button[25]);
		close_programm(e);
	}
}

void			button_settings_canvas(int button, int x, int y, t_env *e)
{
	if (button == MK_LEFT && x >= e->win->x_win / 2 - (150 / 2) - 200 &&
	x <= e->win->x_win / 2 + (150 / 2) - 200 && y >= e->win->y_win / 2 -
	(50 / 2) - 200 && y <= e->win->y_win / 2 + (50 / 2) - 200)
	{
		create_button(e, &e->button[38]);
	}
	if (button == MK_LEFT && x >= e->win->x_win / 2 - (150 / 2) - 200 &&
	x <= e->win->x_win / 2 + (150 / 2) - 200 && y >= e->win->y_win / 2 -
	(50 / 2) + 100 && y <= e->win->y_win / 2 + (50 / 2) + 100)
	{
		create_button(e, &e->button[37]);
	}
	if (button == MK_LEFT && x >= e->win->x_win / 2 - (150 / 2) - 200 &&
	x <= e->win->x_win / 2 + (150 / 2) - 200 && y >= e->win->y_win / 2 -
	(50 / 2) + 200 && y <= e->win->y_win / 2 + (50 / 2) + 200)
	{
		create_button(e, &e->button[35]);
		e->flag.settings = 0;
		e->flag.menu = 1;
	}
}

static void		button_ch_frac_2_str(int button, int x, int y, t_env *e)
{
	if (button == MK_LEFT && x >= e->win->x_win / 2 - (150 / 2) - 300 &&
	x <= e->win->x_win / 2 + (150 / 2) - 300 && y >= e->win->y_win / 2 -
	(50 / 2) + 50 && y <= e->win->y_win / 2 + (50 / 2) + 50)
		button_set_time_machine(e);
	if (button == MK_LEFT && x >= e->win->x_win / 2 - (150 / 2) - 100 &&
	x <= e->win->x_win / 2 + (150 / 2) - 100 && y >= e->win->y_win / 2 -
	(50 / 2) + 50 && y <= e->win->y_win / 2 + (50 / 2) + 50)
		button_set_bracelet(e);
	if (button == MK_LEFT && x >= e->win->x_win / 2 - (150 / 2) + 100 &&
	x <= e->win->x_win / 2 + (150 / 2) + 100 && y >= e->win->y_win / 2 -
	(50 / 2) + 50 && y <= e->win->y_win / 2 + (50 / 2) + 50)
		button_set_butterfly(e);
	if (button == MK_LEFT && x >= e->win->x_win / 2 - (150 / 2) + 300 &&
	x <= e->win->x_win / 2 + (150 / 2) + 300 && y >= e->win->y_win / 2 -
	(50 / 2) + 50 && y <= e->win->y_win / 2 + (50 / 2) + 50)
		button_set_spider(e);
}

void			button_change_frac_canvas(int button, int x, int y, t_env *e)
{
	if (button == MK_LEFT && x >= e->win->x_win / 2 - (150 / 2) - 300 &&
	x <= e->win->x_win / 2 + (150 / 2) - 300 && y >= e->win->y_win / 2 -
	(50 / 2) - 50 && y <= e->win->y_win / 2 + (50 / 2) - 50)
		button_set_mandelbrot(e);
	if (button == MK_LEFT && x >= e->win->x_win / 2 - (150 / 2) - 100 &&
	x <= e->win->x_win / 2 + (150 / 2) - 100 && y >= e->win->y_win / 2 -
	(50 / 2) - 50 && y <= e->win->y_win / 2 + (50 / 2) - 50)
		button_set_julia(e);
	if (button == MK_LEFT && x >= e->win->x_win / 2 - (150 / 2) + 100 &&
	x <= e->win->x_win / 2 + (150 / 2) + 100 && y >= e->win->y_win / 2 -
	(50 / 2) - 50 && y <= e->win->y_win / 2 + (50 / 2) - 50)
		button_set_pyramide(e);
	if (button == MK_LEFT && x >= e->win->x_win / 2 - (150 / 2) + 300 &&
	x <= e->win->x_win / 2 + (150 / 2) + 300 && y >= e->win->y_win / 2 -
	(50 / 2) - 50 && y <= e->win->y_win / 2 + (50 / 2) - 50)
		button_set_puddle(e);
	button_ch_frac_2_str(button, x, y, e);
	if (button == MK_LEFT && x >= e->win->x_win / 2 - (150 / 2) &&
	x <= e->win->x_win / 2 + (150 / 2) && y >= e->win->y_win / 2 -
	(50 / 2) + 150 && y <= e->win->y_win / 2 + (50 / 2) + 150)
	{
		create_button(e, &e->button[34]);
		e->flag.change_fractol = 0;
		e->flag.menu = 1;
	}
}

void			button_pressed(int button, int x, int y, t_env *e)
{
	if (e->flag.menu && e->flag.menu_glb)
		button_menu_canvas(button, x, y, e);
	if (e->flag.settings)
		button_settings_canvas(button, x, y, e);
	if (e->flag.change_fractol)
		button_change_frac_canvas(button, x, y, e);
}
