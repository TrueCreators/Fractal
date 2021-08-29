/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 09:04:20 by sreicher          #+#    #+#             */
/*   Updated: 2018/12/17 17:52:48 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ptr;

	ptr = (char*)malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size + 1);
	return (ptr);
}
