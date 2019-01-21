/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:11:40 by cfrederi          #+#    #+#             */
/*   Updated: 2018/06/04 15:16:34 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*new;
	t_list	*newlist;

	new = *alst;
	while (new)
	{
		newlist = new->next;
		del(new->content, new->content_size);
		free(new);
		new = newlist;
	}
	*alst = NULL;
}
