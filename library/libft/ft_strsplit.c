/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreicher <sreicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:53:53 by sreicher          #+#    #+#             */
/*   Updated: 2020/10/30 15:20:48 by sreicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_words_cnt(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static size_t		ft_word_len(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s == c)
		s++;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

static void			free_split(char **split, int i)
{
	while (i > 0)
	{
		free(split[i]);
		i--;
	}
}

char				**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s || !(split = (char**)malloc(sizeof(char*) *
					(ft_words_cnt(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_words_cnt(s, c))
	{
		k = 0;
		if (!(split[i] = ft_strnew(ft_word_len(&s[j], c))))
			free_split(split, i);
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			split[i][k++] = s[j++];
		split[i][k] = '\0';
	}
	split[i] = 0;
	return (split);
}
