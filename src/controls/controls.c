/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:36:59 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/30 15:30:13 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		close_programm(void *param)
{
	(void)param;
	exit(1);
	return (0);
}

int		mouse_press(int button, int x, int y, t_env *e)
{
	if (button == MK_SCRLUP)
	{
		e->mov->zoom *= 1.2;
		draw(e);
	}
	if (button == MK_SCRLDOWN && e->mov->zoom >= 2)
	{
		e->mov->zoom /= 1.2;
		draw(e);
	}
	if (button == MK_RIGHT)
		e->flag.mouse = (e->flag.mouse + 1) % 2;
	button_pressed(button, x, y, e);
	return (0);
}

int		mouse_move(int x, int y, t_env *e)
{
	if (ft_strcmp(e->fractol, "julia") == 0 && e->flag.mouse)
	{
		mlx_clear_window(e->win->mlx_ptr, e->win->win_ptr);
		if (x - e->win->x_win / 2 < 0)
			e->mov->ju_cre = -0.7 - (x - e->win->x_win / 2) * 0.0001;
		else
			e->mov->ju_cre = -0.7 + (x - e->win->x_win / 2) * 0.0001;
		if (y - e->win->y_win / 2 < 0)
			e->mov->ju_cim = 0.27015 - (y - e->win->y_win / 2) * 0.0001;
		else
			e->mov->ju_cim = 0.27015 + (y - e->win->y_win / 2) * 0.0001;
		draw(e);
	}
	return (0);
}

int		key_press(int keycode, t_env *e)
{
	if (keycode == K_ESC)
		close_programm(((void *)0));
	if (keycode == NK_N1 || keycode == NK_N2 || keycode == NK_N3 ||
	keycode == NK_N0)
		key_change_window(keycode, e);
	if (keycode == NK_PLUS || keycode == NK_MINUS || keycode == K_PLUS
	|| keycode == K_MINUS)
		manipulate(keycode, e);
	if (keycode == K_W || keycode == K_A || keycode == K_S || keycode == K_D ||
keycode == K_UP || keycode == K_DOWN || keycode == K_LEFT || keycode == K_RIGHT)
		move(keycode, e);
	if (keycode == NK_N4 || keycode == NK_N5 || keycode == NK_N6 ||
	keycode == NK_N7 || keycode == NK_N8 || keycode == NK_N9 ||
	keycode == K_H)
		changecolor(keycode, e);
	if (keycode == K_BACKSPACE)
	{
		e->flag.menu_glb = (e->flag.menu_glb + 1) % 2;
	}
	return (0);
}
