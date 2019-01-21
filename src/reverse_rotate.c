/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <cfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:00:04 by cfrederi          #+#    #+#             */
/*   Updated: 2018/08/30 15:43:21 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** shift down all elem by 1. last elem becomes the 1st.
*/

int			r_rotate_a(t_stack *stack)
{
	int		tmp;
	int		tsize;

	tsize = stack->size - 1;
	tmp = stack->data[tsize];
	while (tsize > 0)
	{
		stack->data[tsize] = stack->data[tsize - 1];
		tsize--;
	}
	stack->data[0] = tmp;
	return (1);
}

int			r_rotate_b(t_stack *stack)
{
	int		tmp;
	int		tsize;

	tsize = stack->size - 1;
	tmp = stack->data[tsize];
	while (tsize > 0)
	{
		stack->data[tsize] = stack->data[tsize - 1];
		tsize--;
	}
	stack->data[0] = tmp;
	return (1);
}

/*
** rra and rrb at the same time
*/

int			r_ro_ro(t_stack *a, t_stack *b)
{
	int		tmp;
	int		tsize;

	tsize = a->size - 1;
	tmp = a->data[tsize];
	while (tsize > 0)
	{
		a->data[tsize] = a->data[tsize - 1];
		tsize--;
	}
	a->data[0] = tmp;
	tsize = b->size - 1;
	tmp = b->data[tsize];
	while (tsize > 0)
	{
		b->data[tsize] = b->data[tsize - 1];
		tsize--;
	}
	b->data[0] = tmp;
	return (1);
}
