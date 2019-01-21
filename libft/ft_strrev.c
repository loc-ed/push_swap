/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 12:07:18 by cfrederi          #+#    #+#             */
/*   Updated: 2018/06/04 12:15:40 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*ptr;
	int		a;
	int		b;

	ptr = str;
	a = 0;
	b = 0;
	while (str[a] != '\0')
		a++;
	while (a != 0)
	{
		str[a - 1] = ptr[b];
		a--;
		b++;
	}
	ptr[b] = '\0';
	return (ptr);
}