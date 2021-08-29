/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_events_changefrac2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:33:26 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/30 12:26:18 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	button_set_time_machine(t_env *e)
{
	create_button(e, &e->button[30]);
	e->fractol = "time_machine";
	create_kernel(e->kernel, e);
}

void	button_set_bracelet(t_env *e)
{
	create_button(e, &e->button[31]);
	e->fractol = "bracelet";
	create_kernel(e->kernel, e);
}

void	button_set_butterfly(t_env *e)
{
	create_button(e, &e->button[32]);
	e->fractol = "butterfly";
	create_kernel(e->kernel, e);
}

void	button_set_spider(t_env *e)
{
	create_button(e, &e->button[33]);
	e->fractol = "spider";
	create_kernel(e->kernel, e);
}
