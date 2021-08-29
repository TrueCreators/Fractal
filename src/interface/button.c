/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:42:24 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/30 15:45:47 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_button(t_env *e, t_butt *butt)
{
	int	i;

	butt->pos_x = butt->pos_x - (butt->size_x / 2);
	butt->pos_y = butt->pos_y - (butt->size_y / 2);
	e->img_butt.img_ptr =
	mlx_new_image(e->win->mlx_ptr, butt->size_x, butt->size_y);
	e->img_butt.data =
	(int *)mlx_get_data_addr(e->img_butt.img_ptr, &e->img_butt.bpp,
	&e->img_butt.size_line, &e->img_butt.endian);
	i = -1;
	while (++i < butt->size_x * butt->size_y)
	{
		e->img_butt.data[i] = butt->color_button;
	}
	mlx_put_image_to_window(e->win->mlx_ptr, e->win->win_ptr,
	e->img_butt.img_ptr, butt->pos_x, butt->pos_y);
	if (butt->text)
	{
		mlx_string_put(e->win->mlx_ptr, e->win->win_ptr,
		butt->pos_x + (butt->size_x / 2) - (ft_strlen(butt->text) * 5),
		butt->pos_y + (butt->size_y / 2) - 10, butt->color_text, butt->text);
	}
}

void	help(t_env *e)
{
	mlx_string_put(e->win->mlx_ptr, e->win->win_ptr, e->win->x_win - 320,
		e->win->y_win - 130, RGB(255, 255, 255),
		"ZOOM  : WHEEL || NUM + : NUM -");
	mlx_string_put(e->win->mlx_ptr, e->win->win_ptr, e->win->y_win - 220,
		e->win->y_win - 110, RGB(255, 255, 255), "MOUSE ON  : RIGHT CLICK");
	mlx_string_put(e->win->mlx_ptr, e->win->win_ptr, e->win->y_win - 220,
		e->win->y_win - 90, RGB(255, 255, 255),
		"COLORS : +RGB 456 || -RGB 789");
	mlx_string_put(e->win->mlx_ptr, e->win->win_ptr, e->win->y_win - 220,
		e->win->y_win - 70, RGB(255, 255, 255), "ITERATIONS: + -");
	mlx_string_put(e->win->mlx_ptr, e->win->win_ptr, e->win->y_win - 220,
		e->win->y_win - 30, RGB(255, 255, 255), "MOVE      :  WASD ARROWS");
	mlx_string_put(e->win->mlx_ptr, e->win->win_ptr, 10, e->win->y_win - 50,
		RGB(255, 255, 255), "CLOSE HELP      : H");
	mlx_string_put(e->win->mlx_ptr, e->win->win_ptr, 10, 10,
		RGB(255, 255, 255), "EXIT      : ESC");
}
