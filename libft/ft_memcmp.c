/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:58:11 by cfrederi          #+#    #+#             */
/*   Updated: 2018/06/04 23:15:49 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			a;
	unsigned char	*p1;
	unsigned char	*p2;

	a = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (a < n)
	{
		if (*p1 == *p2)
		{
			p1++;
			p2++;
		}
		else
			return (*p1 - *p2);
		a++;
	}
	if (a == n)
		return (0);
	return (*p1 - *p2);
}
