/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 13:25:36 by cfrederi          #+#    #+#             */
/*   Updated: 2018/06/06 01:19:22 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int n)
{
	size_t	a;

	a = 1;
	while (n /= 10)
		a++;
	return (a);
}

char			*ft_itoa(int n)
{
	size_t			len;
	unsigned int	sign;
	char			*str;

	sign = n;
	len = ft_len(n);
	if (n < 0)
	{
		sign = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str[--len] = (sign % 10) + '0';
	while (sign /= 10)
		str[--len] = (sign % 10) + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
