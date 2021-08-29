/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:50:19 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/30 12:20:25 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			i_settings_press(t_env *e, int x_win, int y_win)
{
	(e->button)[35] = (t_butt) {150, 50, x_win / 2 - 200, y_win / 2 + 200,
	"<- BACK", RGB(0, 255, 0), 0};
	(e->button)[37] = (t_butt) {150, 50, x_win / 2 - 200, y_win / 2 + 100,
	"CREDITS", RGB(0, 255, 0), 0};
	(e->button)[38] = (t_butt) {150, 50, x_win / 2 - 200, y_win / 2 - 200,
	"CONTROLS", RGB(0, 255, 0), 0};
}

static void			i_change_fractol_press(t_env *e, int x_win, int y_win)
{
	(e->button)[26] = (t_butt) {150, 50, x_win / 2 - 300, y_win / 2 - 50,
	"Mandelbrot", RGB(0, 255, 0), 0};
	(e->button)[27] = (t_butt) {150, 50, x_win / 2 - 100, y_win / 2 - 50,
	"Julia", RGB(0, 255, 0), 0};
	(e->button)[28] = (t_butt) {150, 50, x_win / 2 + 100, y_win / 2 - 50,
	"Pyramide", RGB(0, 255, 0), 0};
	(e->button)[29] = (t_butt) {150, 50, x_win / 2 + 300, y_win / 2 - 50,
	"Puddle", RGB(0, 255, 0), 0};
	(e->button)[30] = (t_butt) {150, 50, x_win / 2 - 300, y_win / 2 + 50,
	"Time Machine", RGB(0, 255, 0), 0};
	(e->button)[31] = (t_butt) {150, 50, x_win / 2 - 100, y_win / 2 + 50,
	"Bracelet", RGB(0, 255, 0), 0};
	(e->button)[32] = (t_butt) {150, 50, x_win / 2 + 100, y_win / 2 + 50,
	"Butterfly", RGB(0, 255, 0), 0};
	(e->button)[33] = (t_butt) {150, 50, x_win / 2 + 300, y_win / 2 + 50,
	"Spider", RGB(0, 255, 0), 0};
	(e->button)[34] = (t_butt) {150, 50, x_win / 2, y_win / 2 + 150,
	"BACK", RGB(0, 255, 0), 0};
}

void				init_menu_press(t_env *e, int x_win, int y_win)
{
	(e->button)[22] = (t_butt) {250, 50, x_win / 2, y_win / 2 - 200,
	"PLAY", RGB(0, 255, 0), 0};
	(e->button)[23] = (t_butt) {250, 50, x_win / 2, y_win / 2 - 100,
	"CHANGE FRACTAL", RGB(0, 255, 0), 0};
	(e->button)[24] = (t_butt) {250, 50, x_win / 2, y_win / 2,
	"SETTINGS", RGB(0, 255, 0), 0};
	(e->button)[25] = (t_butt) {250, 50, x_win / 2, y_win / 2 + 100,
	"EXIT", RGB(0, 255, 0), 0};
	i_change_fractol_press(e, x_win, y_win);
	i_settings_press(e, x_win, y_win);
}
