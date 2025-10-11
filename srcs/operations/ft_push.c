/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 19:34:57 by akemalan          #+#    #+#             */
/*   Updated: 2025/10/11 16:01:40 by akemalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*aux_node;

	if (!*src)
		return ;
	aux_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	aux_node->prev = NULL;
	if (!*dest)
	{
		*dest = aux_node;
		aux_node->next = NULL;
	}
	else
	{
		aux_node->next = *dest;
		aux_node->next->prev = aux_node;
		*dest = aux_node;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b, bool print)
{
	push(stack_a, stack_b);
	if (!print)
		ft_putendl_fd("pa", 1);
}

void	pb(t_stack **stack_b, t_stack **stack_a, bool print)
{
	push(stack_b, stack_a);
	if (!print)
		ft_putendl_fd("pb", 1);
}
