/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:10:13 by cfrederi          #+#    #+#             */
/*   Updated: 2018/06/06 01:43:48 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, char const *src, size_t len)
{
	size_t	a;
	size_t	n;

	a = 0;
	n = ft_strlen(src);
	while (a < len)
	{
		if (a > n)
			dst[a] = '\0';
		else
			dst[a] = src[a];
		a++;
	}
	return (dst);
}
