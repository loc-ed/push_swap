/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <cfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:02:35 by cfrederi          #+#    #+#             */
/*   Updated: 2018/08/30 14:59:18 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	swap_a(t_stack *a)
{
	int	i;
	int	tmp;

	i = 0;
	if (a->size < 2)
		return (0);
	tmp = a->data[i];
	a->data[i] = a->data[i + 1];
	a->data[i + 1] = tmp;
	return (1);
}

int	swap_b(t_stack *b)
{
	int	i;
	int	tmp;

	i = 0;
	if (b->size < 2)
		return (0);
	tmp = b->data[i];
	b->data[i] = b->data[i + 1];
	b->data[i + 1] = tmp;
	return (1);
}

int	swap_swap(t_stack *a, t_stack *b)
{
	int i;
	int tmp;

	i = 0;
	if (a->size < 2 || b->size < 2)
		return (0);
	tmp = a->data[i];
	a->data[i] = a->data[i + 1];
	a->data[i + 1] = tmp;
	tmp = b->data[i];
	b->data[i] = b->data[i + 1];
	b->data[i + 1] = tmp;
	return (1);
}
