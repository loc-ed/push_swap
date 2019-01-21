/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 23:44:14 by cfrederi          #+#    #+#             */
/*   Updated: 2018/07/31 23:45:27 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strnew_arr(size_t y, size_t x)
{
	char	**tab;
	char	*tableau2;
	size_t	i;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * y);
	tableau2 = (char *)malloc(sizeof(char) * x * y);
	while (i < y)
	{
		tab[i] = &tableau2[i * x];
		i++;
	}
	return (tab);
}
