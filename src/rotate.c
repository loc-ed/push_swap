/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <cfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:59:07 by cfrederi          #+#    #+#             */
/*   Updated: 2018/09/10 11:01:18 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			rotate_a(t_stack *stack)
{
	int		i;
	int		tmp;
	int		tsize;

	i = 0;
	tsize = stack->size;
	tmp = stack->data[i];
	while (i < tsize)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[tsize - 1] = tmp;
	return (1);
}

int			rotate_b(t_stack *stack)
{
	int		i;
	int		tmp;
	int		tsize;

	i = 0;
	tsize = stack->size;
	tmp = stack->data[i];
	while (i < tsize)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[tsize - 1] = tmp;
	return (1);
}

int			ro_ro(t_stack *a, t_stack *b)
{
	int		i;
	int		tmp;
	int		tsize;

	i = 0;
	tsize = a->size;
	tmp = a->data[i];
	while (i < tsize)
	{
		a->data[i] = a->data[i + 1];
		i++;
	}
	a->data[tsize - 1] = tmp;
	i = 0;
	tsize = b->size;
	tmp = b->data[i];
	while (i < tsize)
	{
		b->data[i] = b->data[i + 1];
		i++;
	}
	b->data[tsize - 1] = tmp;
	return (1);
}
