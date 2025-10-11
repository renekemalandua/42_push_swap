/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:20:45 by akemalan          #+#    #+#             */
/*   Updated: 2025/10/11 15:27:01 by akemalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack		*target_node;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

// Stack utils
int			stack_len(t_stack *stack);
t_stack		*find_last(t_stack *stack);
bool		stack_sorted(t_stack *stack);
t_stack		*find_min(t_stack *stack);
t_stack		*find_max(t_stack *stack);
void		min_on_top(t_stack **a);

// Operations
void		sa(t_stack **stack_a, bool print);
void		sb(t_stack **stack_b, bool print);
void		ss(t_stack **stack_a, t_stack **b, bool print);
void		ra(t_stack **stack_a, bool print);
void		rb(t_stack **stack_b, bool print);
void		rr(t_stack **stack_a, t_stack **b, bool print);
void		rra(t_stack **stack_a, bool print);
void		rrb(t_stack **stack_b, bool print);
void		rrr(t_stack **stack_a, t_stack **stack_b, bool print);
void		pa(t_stack **stack_a, t_stack **stack_b, bool print);
void		pb(t_stack **stack_b, t_stack **stack_a, bool print);

// Stack initiation
char		**mut_split(char *s, char c);

// Error Utils
int			error_syntax(char *str_n);
int			error_duplicate(t_stack *stack_a, int n);
void		free_stack(t_stack **stack);
void		free_errors(t_stack **stack_a);

// initiation
void		init_stack_a(t_stack **stack_a, char **argv);
void		init_nodes_a(t_stack *stack_a, t_stack *stack_b);
void		init_nodes_b(t_stack *stack_a, t_stack *stack_b);
void		current_index(t_stack *stack);
void		set_cheapest(t_stack *stack);
t_stack		*get_cheapest(t_stack *stack);
void		prep_for_push(t_stack **s, t_stack *n, char c);

//***Algorithm
void		sort_three(t_stack **stack_a);
void		push_swap(t_stack **stack_a, t_stack **stack_b);

#endif
