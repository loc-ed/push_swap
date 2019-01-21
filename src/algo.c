/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <cfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 19:41:27 by cfrederi          #+#    #+#             */
/*   Updated: 2018/09/16 06:18:25 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			new_number_inbetween_ends(t_stack *stack, int num)
{
	int		top;
	int		bottom;

	top = stack->data[0];
	bottom = stack->data[stack->size - 1];
	if ((num > top && num < bottom) || (num < top && num > bottom))
		return (1);
	else
		return (0);
}

int			check_all_num_locations(t_stack *stack, int num)
{
	int		i;
	int		min_dif;
	int		right_loc;

	i = 0;
	min_dif = 2147483647;
	if (new_number_inbetween_ends(stack, num))
	{
		right_loc = 0;
		min_dif = ft_abs(stack->data[0] - stack->data[stack->size - 1]);
	}
	while (i < (stack->size - 1))
	{
		if ((num > stack->data[i] && num < stack->data[i + 1]) ||
				(num < stack->data[i] && num > stack->data[i + 1]))
		{
			ft_abs(stack->data[i + 1] - stack->data[i]);
			if (ft_abs(stack->data[i + 1] - stack->data[i]) <
					min_dif && (right_loc = i + 1))
				min_dif = ft_abs(stack->data[i + 1] - stack->data[i]);
		}
		i++;
	}
	return (right_loc);
}

int			find_right_location(t_stack *stack, int num)
{
	int		i;
	int		min_dif;
	int		right_loc;

	i = 0;
	min_dif = 2147483647;
	right_loc = -1;
	if (stack->size == 0)
		return (0);
	else if (num < stack->min_num)
		return (stack->max_idx);
	else if (num > stack->max_num)
		return (stack->max_idx);
	right_loc = check_all_num_locations(stack, num);
	return (right_loc);
}

int			calculate_steps(int index_a, t_stack *a, t_stack *b)
{
	int		steps;
	int		mid_b_idx;
	int		b_loc;

	steps = 0;
	mid_b_idx = 0;
	b_loc = find_right_location(b, a->data[index_a]);
	if (index_a == 0)
		steps = 0;
	else if (index_a <= a->size / 2)
		steps += index_a;
	else
		steps += a->size - index_a;
	steps++;
	mid_b_idx = b->size / 2;
	if (b_loc <= mid_b_idx)
	{
		steps += b_loc;
	}
	else
	{
		steps += b->size - b_loc;
	}
	return (steps);
}

void		set_rotations(t_stack *a, t_stack *b, t_moves *m, int min_steps,
							int min_idx)
{
	int		b_loc;

	b_loc = find_right_location(b, a->data[min_idx]);
	if (min_idx <= a->size / 2)
		m->ra = min_idx;
	else
		m->rra = a->size - min_idx;
	if (b_loc <= b->size / 2)
		m->rb = (min_steps - m->ra - m->rra - 1);
	else
		m->rrb = (min_steps - m->ra - m->rra - 1);
}
