/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:56:13 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/30 15:29:56 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		rgb2hex(int r, int g, int b)
{
	return (((1 << 24) + (r << 16) + (g << 8) + b));
}

int		changecolor(int keycode, t_env *e)
{
	if (keycode == NK_N4 && e->rgb->r <= 255)
		e->rgb->r += 1;
	if (keycode == NK_N5 && e->rgb->g <= 255)
		e->rgb->g += 1;
	if (keycode == NK_N6 && e->rgb->b <= 255)
		e->rgb->b += 1;
	if (keycode == NK_N7 && e->rgb->r >= 1)
		e->rgb->r -= 1;
	if (keycode == NK_N8 && e->rgb->g >= 1)
		e->rgb->g -= 1;
	if (keycode == NK_N9 && e->rgb->b >= 1)
		e->rgb->b -= 1;
	if (e->rgb->r == 0 && e->rgb->g == 0 && e->rgb->b == 0)
	{
		e->rgb->r = 1;
		e->rgb->g = 1;
		e->rgb->b = 1;
	}
	if (keycode == K_H)
		e->flag.helpingame = (e->flag.helpingame + 1) % 2;
	draw(e);
	return (0);
}
