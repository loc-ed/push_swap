/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:54:19 by cfrederi          #+#    #+#             */
/*   Updated: 2018/06/05 17:18:23 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		a;
	int		b;
	char	*n;
	char	*h;

	a = 0;
	b = 0;
	n = (char *)needle;
	h = (char *)haystack;
	if (n[0] == '\0')
		return (h);
	while (h[a] != '\0')
	{
		while (h[a + b] == n[b] && n[b])
			b++;
		if (!n[b])
			return ((char *)&h[a]);
		b = 0;
		a++;
		if (n[b] == '\0')
			return (&h[a - b]);
	}
	return (NULL);
}
