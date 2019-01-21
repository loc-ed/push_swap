/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 18:05:05 by cfrederi          #+#    #+#             */
/*   Updated: 2018/09/10 11:22:12 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char		*handle_three_a(char *op, t_stack *a)
{
	op = update_op(op, "rra");
	r_rotate_a(a);
	op = update_op(op, "sa");
	swap_a(a);
	return (op);
}

char		*handle_three_b(char *op, t_stack *a)
{
	if (a->data[0] > a->data[2])
	{
		op = update_op(op, "ra");
		rotate_a(a);
	}
	else
	{
		op = update_op(op, "sa");
		swap_a(a);
	}
	return (op);
}

char		*handle_three_c(char *op, t_stack *a)
{
	if (is_revsorted(a->data, a->size))
	{
		op = update_op(op, "sa");
		swap_a(a);
		op = update_op(op, "rra");
		r_rotate_a(a);
	}
	else
	{
		op = update_op(op, "rra");
		r_rotate_a(a);
	}
	return (op);
}

char		*handle_three(char *op, t_stack *a)
{
	int		min_num;
	int		*nums;

	nums = a->data;
	find_min(a);
	min_num = a->min_num;
	if (min_num == nums[0])
		op = handle_three_a(op, a);
	else if (min_num == nums[1])
		op = handle_three_b(op, a);
	else
		op = handle_three_c(op, a);
	return (op);
}

char		*handle_small_stack(char *op, t_stack *a)
{
	if (a->size == 2)
	{
		if (a->data[0] > a->data[1])
		{
			op = update_op(op, "sa");
			swap_a(a);
		}
	}
	else if (!sorted(a))
		op = handle_three(op, a);
	return (op);
}
