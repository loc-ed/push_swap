/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrederi <cfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 17:17:06 by cfrederi          #+#    #+#             */
/*   Updated: 2018/09/16 06:43:17 by cfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>

# include "../libft/libft.h"

typedef struct	s_stack
{
	int			*data;
	int			size;
	int			min_num;
	int			max_num;
	int			max_idx;
}				t_stack;

typedef struct	s_moves
{
	int			rb;
	int			ra;
	int			rr;
	int			rrb;
	int			rra;
	int			rrr;
	int			sb;
	int			sa;
	int			ss;
	int			pa;
	int			pb;
}				t_moves;

int				error_check(int ac, char **av);
void			push_swap(t_stack *a, t_stack *b);
void			handle_input(char *line, t_stack *a, t_stack *b);
int				perform_op(char *op, t_stack *a, t_stack *b);
int				sorted(t_stack *stack);

void			stack_print(t_stack *stack, char c);
t_stack			*stack_create(int t, char **av, t_stack *b);
void			stack_destroy(t_stack *a, t_stack *b, char **log, char *line);
void			stack_malloc(t_stack *stack, int size, t_stack *b);
void			stack_fill(int i, t_stack *stack, char **av);

int				check_arg(char **av);
int				check_max(char **av);
int				check_double(char **av);
int				check_nbr(char **av);
int				find_bigger(t_stack *stack, int x);

int				place(t_stack *stack, int tmp);
int				push_a(t_stack *a, t_stack *b);
int				push_b(t_stack *a, t_stack *b);

int				swap_a(t_stack *a);
int				swap_b(t_stack *b);
int				swap_swap(t_stack *a, t_stack *b);

int				rotate_a(t_stack *stack);
int				rotate_b(t_stack *stack);
int				ro_ro(t_stack *a, t_stack *b);
char			*reverse_rotations(char *op, t_stack *a,
									t_stack *b, t_moves *m);
char			*forward_rotations(char *op, t_stack *a,
									t_stack *b, t_moves *m);

int				r_rotate_a(t_stack *stack);
int				r_rotate_b(t_stack *stack);
int				r_ro_ro(t_stack *a, t_stack *b);

void			stack_sort(t_stack *a, t_stack *b);
char			*update_op(char *solution, char *op);
void			zero_stack_moves(t_moves *m);
char			*move_to_b(char *op, t_stack *a, t_stack *b, t_moves *m);

int				find_min(t_stack *stack);
int				is_revsorted(int *data, int size);
int				arg_split_check(char **log);
void			free_dbl(char **log);

char			*handle_three_a(char *solution, t_stack *a);
char			*handle_three_b(char *solution, t_stack *a);
char			*handle_three_c(char *solution, t_stack *a);
char			*handle_three(char *solution, t_stack *a);
char			*handle_small_stack(char *solution, t_stack *a);

char			*min_solve(char *solution, t_stack *a, t_stack *b);
char			*move_min_num(char *solution, t_stack *a, int min_idx);

void			find_max(t_stack *stack);
char			*put_max_on_top(char *op, t_stack *b);
char			*order_b(char *op, t_stack *a, t_stack *b);
char			*push(char *op, t_stack *a, t_stack *b, t_moves *m);
char			*solve(char *op, t_stack *a, t_stack *b, t_moves *m);

int				new_number_inbetween_ends(t_stack *stack, int num);
int				check_all_num_locations(t_stack *stack, int num);
int				find_right_location(t_stack *stack, int num);
int				calculate_steps(int index_a, t_stack *a, t_stack *b);
void			set_rotations(t_stack *a, t_stack *b,
									t_moves *m, int steps, int min_idx);
int				find_shortest_path(t_stack *a, t_stack *b, t_moves *m);

#endif
