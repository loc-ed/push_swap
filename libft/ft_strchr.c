/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 09:28:21 by cfrederi          #+#    #+#             */
/*   Updated: 2018/06/05 16:42:52 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		a;

	a = 0;
	while (s[a] != '\0')
	{
		if (s[a] == (char)c)
			return ((char *)(s + a));
		a++;
	}
	if ((char)c == '\0')
		return ((char *)(s + a));
	return (NULL);
}
