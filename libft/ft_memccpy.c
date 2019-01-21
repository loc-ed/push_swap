/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:25:42 by cfrederi          #+#    #+#             */
/*   Updated: 2018/06/05 16:20:30 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			a;
	unsigned char	*p1;
	unsigned char	*p2;

	a = 0;
	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	while (a < n)
	{
		*p1++ = *p2;
		if (*p2++ == (unsigned char)c)
			return (p1);
		a++;
	}
	return (NULL);
}
