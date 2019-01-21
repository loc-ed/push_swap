/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:58:15 by cfrederi          #+#    #+#             */
/*   Updated: 2018/06/06 01:24:06 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_len(char const *src, char c)
{
	int i;
	int	len;

	i = 0;
	len = 0;
	while (src[i] == c)
		i++;
	while (src[i] != c && src[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static int	ft_word_count(char const *src, char c)
{
	int i;
	int wcount;

	i = 0;
	wcount = 0;
	if (!src)
		return (0);
	while (src[i])
	{
		while (src[i] == c)
			i++;
		if (src[i] != c && src[i] != '\0')
			wcount++;
		while (src[i] != '\0' && src[i] != c)
			i++;
	}
	return (wcount);
}

char		**ft_strsplit(char const *s, char c)
{
	int		a;
	int		b;
	int		i;
	char	**new;

	a = -1;
	b = 0;
	if (!s || !(new = (char **)malloc(sizeof(*new) *
					(ft_word_count(s, c) + 1))))
		return (NULL);
	while (++a < ft_word_count(s, c))
	{
		i = 0;
		if (!(new[a] = ft_strnew(ft_word_len(&s[b], c) + 1)))
			new[a] = NULL;
		while (s[b] == c)
			b++;
		while (s[b] != c && s[b])
			new[a][i++] = s[b++];
		new[a][i] = '\0';
	}
	new[a] = 0;
	return (new);
}
