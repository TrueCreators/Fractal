/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:03:53 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/30 15:43:25 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			init_settings(t_env *e, int x_win, int y_win)
{
	(e->button)[13] = (t_butt) {150, 50, x_win / 2 - 200, y_win / 2 - 200,
	"CONTROLS", RGB(255, 255, 255), 0};
	(e->button)[14] = (t_butt) {500, 50, x_win / 2 + 200, y_win / 2 - 200,
	"INPUT                            DESCRIPTION", RGB(255, 255, 255), 0};
	(e->button)[15] = (t_butt) {500, 50, x_win / 2 + 200, y_win / 2 - 150,
	"W, A, S, D                        Move fractal", RGB(255, 255, 255), 0};
	(e->button)[16] = (t_butt) {500, 50, x_win / 2 + 200, y_win / 2 - 100,
	"H                                        HELP", RGB(255, 255, 255), 0};
	(e->button)[17] = (t_butt) {500, 50, x_win / 2 + 200, y_win / 2 - 50,
	"+, -                                 Iteration", RGB(255, 255, 255), 0};
	(e->button)[18] = (t_butt) {500, 50, x_win / 2 + 200, y_win / 2,
	"NUM +, NUM -                             ZOOM", RGB(255, 255, 255), 0};
	(e->button)[19] = (t_butt) {500, 50, x_win / 2 + 200, y_win / 2 + 50,
	"WHEEL                                    ZOOM", RGB(255, 255, 255), 0};
	(e->button)[20] = (t_butt) {500, 50, x_win / 2 + 200, y_win / 2 + 100,
	"NUM 4-6, NUM 7-9                  +- RGB COLOR", RGB(255, 255, 255), 0};
	(e->button)[21] = (t_butt) {150, 50, x_win / 2 - 200, y_win / 2 + 200,
	"<- BACK", RGB(255, 255, 255), 0};
	(e->button)[36] = (t_butt) {150, 50, x_win / 2 - 200, y_win / 2 + 100,
	"CREDITS", RGB(255, 255, 255), 0};
}

static void			init_change_fractol(t_env *e, int x_win, int y_win)
{
	(e->button)[4] = (t_butt) {150, 50, x_win / 2 - 300, y_win / 2 - 50,
	"Mandelbrot", RGB(255, 255, 255), 0};
	(e->button)[5] = (t_butt) {150, 50, x_win / 2 - 100, y_win / 2 - 50,
	"Julia", RGB(255, 255, 255), 0};
	(e->button)[6] = (t_butt) {150, 50, x_win / 2 + 100, y_win / 2 - 50,
	"Pyramide", RGB(255, 255, 255), 0};
	(e->button)[7] = (t_butt) {150, 50, x_win / 2 + 300, y_win / 2 - 50,
	"Puddle", RGB(255, 255, 255), 0};
	(e->button)[8] = (t_butt) {150, 50, x_win / 2 - 300, y_win / 2 + 50,
	"Time Machine", RGB(255, 255, 255), 0};
	(e->button)[9] = (t_butt) {150, 50, x_win / 2 - 100, y_win / 2 + 50,
	"Bracelet", RGB(255, 255, 255), 0};
	(e->button)[10] = (t_butt) {150, 50, x_win / 2 + 100, y_win / 2 + 50,
	"Butterfly", RGB(255, 255, 255), 0};
	(e->button)[11] = (t_butt) {150, 50, x_win / 2 + 300, y_win / 2 + 50,
	"Spider", RGB(255, 255, 255), 0};
	(e->button)[12] = (t_butt) {150, 50, x_win / 2, y_win / 2 + 150,
	"BACK", RGB(255, 255, 255), 0};
}

void				init_menu(t_env *e, int x_win, int y_win)
{
	(e->button)[0] = (t_butt) {250, 50, x_win / 2, y_win / 2 - 200,
	"PLAY", RGB(255, 255, 255), 0};
	(e->button)[1] = (t_butt) {250, 50, x_win / 2, y_win / 2 - 100,
	"CHANGE FRACTAL", RGB(255, 255, 255), 0};
	(e->button)[2] = (t_butt) {250, 50, x_win / 2, y_win / 2,
	"SETTINGS", RGB(255, 255, 255), 0};
	(e->button)[3] = (t_butt) {250, 50, x_win / 2, y_win / 2 + 100,
	"EXIT", RGB(255, 255, 255), 0};
	init_change_fractol(e, x_win, y_win);
	init_settings(e, x_win, y_win);
}
