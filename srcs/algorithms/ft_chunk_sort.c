/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:17:19 by akemalan          #+#    #+#             */
/*   Updated: 2025/09/26 09:17:03 by akemalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

// em algum arquivo utils (ex: ft_stack_index_utils.c)
static int get_max(t_list *stack, int val)
{
    int max;

    if (!stack)
        return (val);
    max = stack->index;
    while (stack)
    {
        if (stack->index > max)
            max = stack->index;
        stack = stack->next;
    }
    return (max);
}

// move maior elemento de stack B para topo
static void	move_max_to_top(t_list **stack)
{
	int	dist;

	dist = get_distance(stack, get_max(*stack, -1));
	make_top(stack, dist);
}

static void	push_chunk_to_b(t_list **a, t_list **b, int min, int max)
{
	t_list	*head;
	int		size;
	int		i;

	size = ft_lstsize(*a);
	i = 0;
	while (i < size)
	{
		head = *a;
		if (head->index >= min && head->index <= max)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

void	chunk_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	chunk_size;
	int	min;
	int	max;

	index_stack_bs(stack_a);
	size = ft_lstsize(*stack_a);
	chunk_size = size / 5; // 5 chunks para 100 elementos
	min = 0;
	while (min < size)
	{
		max = min + chunk_size - 1;
		if (max >= size)
			max = size - 1;
		push_chunk_to_b(stack_a, stack_b, min, max);
		min += chunk_size;
	}
	while (ft_lstsize(*stack_b))
	{
		move_max_to_top(stack_b);
		pa(stack_a, stack_b);
	}
}
