/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <cfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 15:04:26 by cfrederi          #+#    #+#             */
/*   Updated: 2018/09/16 06:18:25 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char		*update_op(char *solution, char *op)
{
	ft_strcat(solution, op);
	ft_strcat(solution, "\n");
	return (solution);
}

void		zero_stack_moves(t_moves *m)
{
	m->rb = 0;
	m->ra = 0;
	m->rr = 0;
	m->rrb = 0;
	m->rra = 0;
	m->rrr = 0;
	m->sb = 0;
	m->sa = 0;
	m->ss = 0;
	m->pb = 0;
	m->pa = 0;
}

int			find_shortest_path(t_stack *a, t_stack *b, t_moves *m)
{
	int		min_steps;
	int		min_idx;
	int		i;
	int		steps;

	i = 0;
	min_steps = 2147483647;
	min_idx = 2147483647;
	while (i < a->size)
	{
		steps = calculate_steps(i, a, b);
		if (steps < min_steps)
		{
			min_steps = steps;
			min_idx = i;
		}
		i++;
	}
	set_rotations(a, b, m, min_steps, min_idx);
	return (min_idx);
}

char		*move_to_b(char *op, t_stack *a, t_stack *b, t_moves *m)
{
	int		idx_to_move;
	int		num_to_move;
	int		mid_a;
	int		mid_b;
	int		right_place;

	idx_to_move = find_shortest_path(a, b, m);
	num_to_move = a->data[idx_to_move];
	mid_a = a->size / 2;
	mid_b = b->data[b->size / 2];
	right_place = find_right_location(b, num_to_move);
	op = reverse_rotations(op, a, b, m);
	op = forward_rotations(op, a, b, m);
	op = update_op(op, "pb");
	push_b(a, b);
	return (op);
}

void		stack_sort(t_stack *a, t_stack *b)
{
	char	*op;
	t_moves	*m;

	m = malloc(sizeof(int) * 1000);
	zero_stack_moves(m);
	op = (char *)malloc(sizeof(char) * 100000);
	if (a->size <= 3)
		op = handle_small_stack(op, a);
	else if (a->size < 10)
		op = min_solve(op, a, b);
	else
		op = solve(op, a, b, m);
	ft_putstr(op);
	free(op);
	free(m);
}
