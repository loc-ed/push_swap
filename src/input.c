/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <cfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 22:36:49 by cfrederi          #+#    #+#             */
/*   Updated: 2018/09/16 07:00:23 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		handle_input(char *line, t_stack *a, t_stack *b)
{
	while ((get_next_line(0, &line) == 1))
	{
		if (!perform_op(line, a, b))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		ft_strdel(&line);
	}
	if (sorted(a) && b->size == 0)
		ft_putstr("OK\n");
	else if (!sorted(a) || b->size > 0)
		ft_putstr("KO\n");
}

int			perform_op(char *op, t_stack *a, t_stack *b)
{
	if (ft_strcmp(op, "sa") == 0)
		swap_a(a);
	else if (ft_strcmp(op, "sb") == 0)
		swap_b(b);
	else if (ft_strcmp(op, "ss") == 0)
		swap_swap(a, b);
	else if (ft_strcmp(op, "pa") == 0)
		push_a(a, b);
	else if (ft_strcmp(op, "pb") == 0)
		push_b(a, b);
	else if (ft_strcmp(op, "ra") == 0)
		rotate_a(a);
	else if (ft_strcmp(op, "rb") == 0)
		rotate_b(b);
	else if (ft_strcmp(op, "rr") == 0)
		ro_ro(a, b);
	else if (ft_strcmp(op, "rra") == 0)
		r_rotate_a(a);
	else if (ft_strcmp(op, "rrb") == 0)
		r_rotate_b(b);
	else if (ft_strcmp(op, "rrr") == 0)
		r_ro_ro(a, b);
	else
		return (0);
	return (1);
}
