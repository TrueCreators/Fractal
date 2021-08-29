/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:51:30 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/29 22:10:48 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			menu_text(t_env *e)
{
	int	i;

	i = -1;
	while (++i < 4)
		create_button(e, &e->button[i]);
}

void			change_fractol(t_env *e)
{
	int	i;

	i = 3;
	while (++i < 13)
		create_button(e, &e->button[i]);
}

static void		settings(t_env *e)
{
	int	i;

	i = 12;
	while (++i < 22)
		create_button(e, &e->button[i]);
	create_button(e, &e->button[36]);
}

void			main_menu(t_env *e)
{
	if (e->flag.menu)
		menu_text(e);
	if (e->flag.change_fractol)
		change_fractol(e);
	if (e->flag.settings)
		settings(e);
}
