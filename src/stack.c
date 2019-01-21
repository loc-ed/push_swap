/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <cfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:01:32 by cfrederi          #+#    #+#             */
/*   Updated: 2018/09/16 06:43:17 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			stack_fill(int i, t_stack *stack, char **av)
{
	int			*tmp;

	tmp = stack->data;
	while ((av[i] && av[i][0] == '-') || !ft_strcmp(av[i], "--"))
	{
		if (ft_isnum(&av[i][1]))
			break ;
		i++;
	}
	while (av[i])
	{
		*tmp = ft_atoi(av[i]);
		tmp++;
		i++;
	}
}

void			stack_malloc(t_stack *stack, int size, t_stack *b)
{
	stack->data = (int *)malloc(sizeof(int) * (size + 1));
	stack->size = size;
	b->data = (int *)malloc(sizeof(int) * (size + 1));
	b->size = 0;
}

t_stack			*stack_create(int t, char **av, t_stack *b)
{
	int			i;
	int			size;
	t_stack		*stack;

	size = 0;
	stack = malloc(sizeof(t_stack *));
	while ((av[t] && av[t][0] == '-') || !ft_strcmp(av[t], "--"))
	{
		if (ft_isnum(&av[t][1]))
			break ;
		t++;
	}
	i = t;
	while (av[i])
		i++;
	size = i - t;
	stack_malloc(stack, size, b);
	stack_fill(t, stack, av);
	return (stack);
}

void			stack_destroy(t_stack *a, t_stack *b, char **log, char *line)
{
	free(a->data);
	a->size = 0;
	free(a);
	free(b->data);
	b->size = 0;
	free(b);
	if (log)
		free_dbl(log);
	if (line)
		ft_strdel(&line);
}

void			stack_print(t_stack *stack, char c)
{
	int		i;

	i = 0;
	ft_putchar(c);
	while (i < stack->size)
	{
		ft_putnbr(stack->data[i]);
		ft_putchar('|');
		i++;
	}
	ft_putchar('\n');
}
