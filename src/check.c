/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <cfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:35:01 by cfrederi          #+#    #+#             */
/*   Updated: 2018/09/16 06:53:13 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_bigger(t_stack *stack, int x)
{
	int	i;

	i = 1;
	x = (stack->data)[0];
	while (i < stack->size)
	{
		if ((stack->data)[i] < x)
			x = (stack->data)[i];
		i++;
	}
	i = 0;
	while ((stack->data)[i] != x)
		i++;
	return (i);
}

int			check_nbr(char **av)
{
	int		i;
	int		j;

	i = 1;
	while ((av[i] && av[i][0] == '-') || !ft_strcmp(av[i], "--"))
	{
		if (ft_isnum(&av[i][1]))
			break ;
		i++;
	}
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (!ft_isnum(&av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			check_double(char **av)
{
	int		i;
	int		j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (!strcmp(av[i], av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			check_max(char **av)
{
	int		i;
	long	nbr;

	i = 1;
	nbr = 0;
	while (av[i])
	{
		nbr = ft_atol(av[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int			check_arg(char **av)
{
	if (!check_nbr(av) || !check_double(av) || !check_max(av))
		return (0);
	return (1);
}
