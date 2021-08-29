/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_events_menu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:22:27 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/29 21:46:34 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	button_play_canvas(t_env *e)
{
	create_button(e, &e->button[22]);
	e->flag.menu_glb = 0;
	e->flag.background = 0;
	e->flag.mouse = 0;
	draw(e);
}

void	button_change_fractol_canvas(t_env *e)
{
	create_button(e, &e->button[23]);
	e->flag.menu = 0;
	e->flag.change_fractol = 1;
}

void	button_settings_e_canvas(t_env *e)
{
	create_button(e, &e->button[24]);
	e->flag.menu = 0;
	e->flag.settings = 1;
}
