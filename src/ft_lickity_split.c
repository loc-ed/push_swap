/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lickity_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <cfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:51:06 by cfrederi          #+#    #+#             */
/*   Updated: 2018/09/16 06:53:13 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		arg_split_check(char **log)
{
	int		i;

	i = 0;
	while (log[i])
		i++;
	if (i <= 1)
		exit(1);
	return (0);
}

void	free_dbl(char **log)
{
	int		i;

	i = 0;
	while (log[i])
	{
		free(log[i]);
		i++;
	}
	free(log);
}

int		is_revsorted(int *data, int size)
{
	int		i;

	i = 0;
	while (i < (size - 1))
	{
		if (data[i] < data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		find_min(t_stack *stack)
{
	int		num;
	int		idx;
	int		i;

	i = 0;
	idx = 0;
	num = stack->data[i];
	while (++i < stack->size)
	{
		if (num > stack->data[i])
		{
			num = stack->data[i];
			idx = i;
		}
	}
	stack->min_num = num;
	return (idx);
}
