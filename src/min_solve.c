/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 18:51:48 by cfrederi          #+#    #+#             */
/*   Updated: 2018/09/10 11:18:33 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char		*move_min_num(char *op, t_stack *a, int min_idx)
{
	if (min_idx == 1)
	{
		swap_a(a);
		op = update_op(op, "sa");
	}
	else if (min_idx > a->size / 2)
	{
		r_rotate_a(a);
		op = update_op(op, "rra");
	}
	else if (min_idx <= a->size / 2)
	{
		rotate_a(a);
		op = update_op(op, "ra");
	}
	return (op);
}

char		*min_solve(char *op, t_stack *a, t_stack *b)
{
	int		top;
	int		min_idx;

	while (!(sorted(a) && !b->size))
	{
		if (a->size == 3)
			op = handle_three(op, a);
		min_idx = find_min(a);
		while ((top = a->data[0]) && top != a->min_num)
			op = move_min_num(op, a, min_idx);
		if (!sorted(a))
		{
			op = update_op(op, "pb");
			push_b(a, b);
		}
		else
		{
			while (b->size)
			{
				op = update_op(op, "pa");
				push_a(a, b);
			}
		}
	}
	return (op);
}

char		*reverse_rotations(char *op, t_stack *a, t_stack *b, t_moves *m)
{
	while (((m->rrb)) && ((m->rra)))
	{
		op = update_op(op, "rrr");
		r_ro_ro(a, b);
		(m->rra)--;
		(m->rrb)--;
	}
	while (((m->rrb)))
	{
		op = update_op(op, "rrb");
		r_rotate_b(b);
		(m->rrb)--;
	}
	while (((m->rra)))
	{
		op = update_op(op, "rra");
		r_rotate_a(a);
		(m->rra)--;
	}
	return (op);
}

char		*forward_rotations(char *op, t_stack *a, t_stack *b, t_moves *m)
{
	while (((m->rb)) && ((m->ra)))
	{
		op = update_op(op, "rr");
		ro_ro(a, b);
		(m->ra)--;
		(m->rb)--;
	}
	while (((m->rb)))
	{
		op = update_op(op, "rb");
		rotate_b(b);
		(m->rb)--;
	}
	while (((m->ra)))
	{
		op = update_op(op, "ra");
		rotate_a(a);
		(m->ra)--;
	}
	return (op);
}
