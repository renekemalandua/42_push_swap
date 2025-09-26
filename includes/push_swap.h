/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 22:30:29 by akemalan          #+#    #+#             */
/*   Updated: 2025/09/26 08:48:01 by akemalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

// List utils
t_list	*ft_lstlast(t_list *head);
int		ft_lstsize(t_list *head);

t_list	*ft_lstnew(int value);
void	ft_lstadd_front(t_list **stack, t_list *new);
void	ft_lstadd_back(t_list **stack, t_list *new);

void	ft_error(char *msg);
void	ft_check_args(int argc, char **argv);
void	ft_free(char **str);

int		get_distance(t_list **stack, int index);
void	make_top(t_list **stack, int distance);
void	free_stack(t_list **stack);

// Algorithm utils
int		is_sorted(t_list **stack);
void	index_stack(t_list **stack);
int		get_min(t_list **stack, int val);
int		get_max_bits(t_list **stack);
void	index_stack_bs(t_list **stack);

// Instructions
int		push(t_list **stack_to, t_list **stack_from);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_b, t_list **stack_a);

int		swap(t_list **stack);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);

int		rotate(t_list **stack);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);

int		reverse_rotate(t_list **stack);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

// Algorithms
void	radix_sort(t_list **stack_a, t_list **stack_b);
void	sort_5(t_list **stack_a, t_list **stack_b);
void	simple_sort(t_list **stack_a, t_list **stack_b);
void	chunk_sort(t_list **stack_a, t_list **stack_b);

//extern int	g_operation_count;
//void	feedback_operations(int argc, int total_ops);

#endif
