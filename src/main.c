/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:50:46 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/30 15:52:25 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		faq_message(void)
{
	ft_putendl("usage: ./fractol [julia, mandelbrot, pyramide, puddle,\
			time_machine, bracelet, butterfly, spider]\
	Example: ./fractol julia");
	exit(-1);
}

void		error_exit(char *str)
{
	if (!str)
		ft_putendl("Error");
	else
	{
		ft_putstr("Error:");
		ft_putendl(str);
	}
}

int			main(int argc, char **argv)
{
	if (argc == 2 &&
	(ft_strcmp(argv[1], "mandelbrot") == 0 ||
	ft_strcmp(argv[1], "julia") == 0 ||
	ft_strcmp(argv[1], "pyramide") == 0 ||
	ft_strcmp(argv[1], "puddle") == 0 ||
	ft_strcmp(argv[1], "time_machine") == 0 ||
	ft_strcmp(argv[1], "bracelet") == 0 ||
	ft_strcmp(argv[1], "butterfly") == 0 ||
	ft_strcmp(argv[1], "spider") == 0))
		fractol(argv[1]);
	else
		faq_message();
}
