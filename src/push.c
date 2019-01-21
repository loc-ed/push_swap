/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <cfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 10:27:32 by cfrederi          #+#    #+#             */
/*   Updated: 2018/09/15 22:47:29 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			place(t_stack *stack, int tmp)
{
	int		tsize;

	tsize = stack->size;
	if (tsize != 0)
	{
		while (tsize > 0)
		{
			stack->data[tsize] = stack->data[tsize - 1];
			tsize--;
		}
	}
	stack->data[0] = tmp;
	stack->size++;
	return (1);
}

int			push_a(t_stack *a, t_stack *b)
{
	int		tmp;
	int		i;

	i = 0;
	if (b->size < 1)
		return (0);
	tmp = b->data[0];
	while (i < b->size)
	{
		b->data[i] = b->data[i + 1];
		i++;
	}
	b->size--;
	place(a, tmp);
	return (1);
}

int			push_b(t_stack *a, t_stack *b)
{
	int		tmp;
	int		i;

	i = 0;
	if (a->size < 1)
		return (0);
	tmp = a->data[i];
	while (i < a->size)
	{
		a->data[i] = a->data[i + 1];
		i++;
	}
	a->size--;
	place(b, tmp);
	return (1);
}
