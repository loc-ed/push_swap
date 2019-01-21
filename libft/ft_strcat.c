/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:34:38 by cfrederi          #+#    #+#             */
/*   Updated: 2018/06/03 17:47:25 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t a;
	size_t b;

	a = 0;
	b = 0;
	while (dst[a] != '\0')
	{
		a++;
	}
	while (src[b] != '\0')
	{
		dst[a + b] = src[b];
		b++;
	}
	dst[a + b] = '\0';
	return (dst);
}
