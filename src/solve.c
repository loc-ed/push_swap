/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <cfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 19:25:06 by cfrederi          #+#    #+#             */
/*   Updated: 2018/09/16 05:44:41 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_max(t_stack *stack)
{
	int	i;
	int	max_num;
	int	max_idx;

	i = 1;
	max_num = stack->data[0];
	max_idx = 0;
	while (i < stack->size)
	{
		if (stack->data[i] > max_num)
		{
			max_num = stack->data[i];
			max_idx = i;
		}
		i++;
	}
	stack->max_idx = max_idx;
	stack->max_num = max_num;
}

char	*put_max_on_top(char *op, t_stack *b)
{
	int	max_idx;
	int	max_num;
	int	mid_idx;

	max_idx = b->max_idx;
	max_num = b->max_num;
	mid_idx = b->size / 2;
	while (b->data[0] != max_num)
	{
		if (max_idx < mid_idx)
		{
			op = update_op(op, "rb");
			rotate_b(b);
		}
		else
		{
			op = update_op(op, "rrb");
			r_rotate_b(b);
		}
	}
	return (op);
}

char	*order_b(char *op, t_stack *a, t_stack *b)
{
	int	a_top;
	int	b_top;
	int	b_next;

	a_top = a->data[0];
	b_top = b->data[0];
	b_next = b->data[1];
	if (!((a_top > b_top && b_top > b_next) ||
			(b_top > b_next && b_next > a_top) ||
				(b_top < a_top && a_top < b_next)))
	{
		op = update_op(op, "sb");
		swap_b(b);
	}
	op = update_op(op, "pb");
	push_b(a, b);
	return (op);
}

char	*push(char *op, t_stack *a, t_stack *b, t_moves *m)
{
	int		min_idx;

	while (a->size > 1)
	{
		min_idx = find_min(b);
		find_max(b);
		if (b->size == 2)
			op = order_b(op, a, b);
		else
			op = move_to_b(op, a, b, m);
		zero_stack_moves(m);
	}
	find_max(b);
	op = put_max_on_top(op, b);
	return (op);
}

char	*solve(char *op, t_stack *a, t_stack *b, t_moves *m)
{
	op = push(op, a, b, m);
	while (b->data[0] > a->data[a->size - 1] && b->size)
	{
		op = update_op(op, "pa");
		push_a(a, b);
	}
	if (b->size)
	{
		op = update_op(op, "rra");
		r_rotate_a(a);
		while (b->size)
		{
			op = update_op(op, "pa");
			push_a(a, b);
		}
	}
	if (a->data[0] > a->data[a->size - 1])
	{
		op = update_op(op, "rra");
		r_rotate_a(a);
	}
	return (op);
}
