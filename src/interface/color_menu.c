/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:56:51 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/29 22:05:10 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		next_i_color_menu(t_env *e, int i)
{
	if (i == 10)
	{
		e->rgb->r = 0;
		e->rgb->g = 3;
		e->rgb->b = 3;
	}
	if (i == 12)
	{
		e->rgb->r = 3;
		e->rgb->g = 3;
		e->rgb->b = 3;
	}
	if (i == 14)
	{
		e->rgb->r = 0;
		e->rgb->g = 0;
		e->rgb->b = 3;
		e->flag.color = 0;
	}
}

void			color_menu(t_env *e, int i)
{
	if (i == 2)
	{
		e->rgb->r = 3;
		e->rgb->g = 0;
		e->rgb->b = 0;
	}
	if (i == 4)
	{
		e->rgb->r = 0;
		e->rgb->g = 3;
	}
	if (i == 6)
	{
		e->rgb->r = 3;
		e->rgb->g = 3;
	}
	if (i == 8)
	{
		e->rgb->r = 3;
		e->rgb->g = 0;
		e->rgb->b = 3;
	}
	next_i_color_menu(e, i);
}
