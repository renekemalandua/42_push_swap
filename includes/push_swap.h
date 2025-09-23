/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 22:30:29 by akemalan          #+#    #+#             */
/*   Updated: 2025/09/23 19:15:37 by akemalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

// List utils
t_list	*ft_list_last(t_list *head);
int		ft_list_size(t_list *head);
void	ft_print_list(t_list *head);

t_list	*ft_lstlast(t_list *head);
int		ft_lstsize(t_list *head);
void	printList(t_list *head);

t_list	*ft_list_new(int data);
void	ft_list_push_front(t_list **stack, t_list *node);
void	ft_list_push_back(t_list **stack, t_list *node);

void	ft_error(char *msg);
void	ft_check_args(int argc, char **argv);
void	ft_free(char **str);

int		ft_get_distance(t_list **stack, int index);
void	ft_make_top(t_list **stack, int distance);
void	ft_free_stack(t_list **stack);

// Algorithm utils
void	ft_index_stack(t_list **stack);
int		ft_is_sorted(t_list **stack);
int		ft_get_min(t_list **stack, int data);

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

#endif
