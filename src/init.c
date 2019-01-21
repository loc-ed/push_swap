/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <cfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 17:21:34 by cfrederi          #+#    #+#             */
/*   Updated: 2018/09/16 07:00:23 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			error_check(int ac, char **av)
{
	int			i;
	int			j;

	i = 1;
	j = 0;
	if (ac < 2 || !av)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	else if (!check_arg(av))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (0);
}

int			sorted(t_stack *stack)
{
	int			i;
	int			tsize;

	i = 0;
	tsize = stack->size;
	while (i < (tsize - 1))
	{
		if (stack->data[i] > stack->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	char		*line;
	char		**log;

	b = malloc(sizeof(t_stack *));
	log = NULL;
	line = NULL;
	if (ac == 1)
		exit(1);
	else if (ac == 2)
	{
		log = ft_strsplit(av[1], ' ');
		arg_split_check(log);
		a = stack_create(0, log, b);
	}
	else
	{
		error_check(ac, av);
		a = stack_create(1, av, b);
	}
	handle_input(line, a, b);
	stack_destroy(a, b, log, line);
	return (0);
}
