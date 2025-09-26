/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:17:19 by akemalan          #+#    #+#             */
/*   Updated: 2025/09/24 22:53:03 by akemalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_to_top(t_list **stack, int index)
{
	int	pos;
	int	size;

	pos = get_distance(stack, index);
	size = ft_lstsize(*stack);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(stack);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(stack);
	}
}

static int	get_max(t_list **stack)
{
	t_list	*head;
	int		max;

	head = *stack;
	max = head->index;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	return (max);
}


static void	push_back_sorted(t_list **stack_a, t_list **stack_b)
{
	int	max_index;

	while (*stack_b)
	{
		max_index = get_max(stack_b);
		move_to_top(stack_b, max_index);
		pa(stack_a, stack_b);
	}
}

void	chunk_sort(t_list **stack_a, t_list **stack_b)
{
	int		size;
	int		chunks;
	int		chunk_size;
	int		start;
	int		end;
	t_list	*head;

	ft_putendl_fd("Chunk sorting", 1);
	size = ft_lstsize(*stack_a);
	chunks = 5;
	if (size > 100)
		chunks = 11;
	chunk_size = size / chunks;
	start = 0;
	end = chunk_size - 1;
	while (*stack_a)
	{
		head = *stack_a;
		while (head)
		{
			if (head->index >= start && head->index <= end)
			{
				move_to_top(stack_a, head->index);
				pb(stack_a, stack_b);
				if ((*stack_b)->index < start + (chunk_size / 2))
					rb(stack_b);
				break ;
			}
			head = head->next;
		}
		if (!head)
		{
			start += chunk_size;
			end += chunk_size;
			if (end >= size)
				end = size - 1;
		}
	}
	push_back_sorted(stack_a, stack_b);
}
