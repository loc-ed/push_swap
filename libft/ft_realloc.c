/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 15:02:06 by cfrederi          #+#    #+#             */
/*   Updated: 2018/09/05 15:31:30 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_realloc(char *ptr, size_t n)
{
	char	*new;

	new = (char*)malloc(n);
	ft_bzero(new, n);
	ft_memcpy(new, ptr, ft_strlen(ptr) + 1);
	free(ptr);
	return (new);
}
