/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 08:13:28 by akemalan          #+#    #+#             */
/*   Updated: 2025/09/26 08:46:12 by akemalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

// Função 1: bubble sort explícito para arrays
static void	bubble_sort(int *arr, int n)
{
	int i, tmp, keep, end;

	end = n;
	keep = 1;
	while (keep)
	{
		keep = 0;
		i = 0;
		while (i < end - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				keep = 1;
			}
			i++;
		}
		end--;
	}
}

// Função 2: copia os valores da stack para um array e ordena
static int	*copy_and_sort_stack(t_list *stack, int size)
{
	int i;
	int *arr;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		ft_error("malloc failed");

	i = 0;
	while (i < size)
	{
		arr[i] = stack->value;
		stack = stack->next;
		i++;
	}

	bubble_sort(arr, size);
	return (arr);
}

// Função 3: atribui os índices à stack
static void	assign_indices_to_stack(t_list *stack, int *sorted, int size)
{
	int i, j;

	i = 0;
	while (stack && i < size)
	{
		j = 0;
		while (j < size)
		{
			if (stack->value == sorted[j])
			{
				stack->index = j;
				break ;
			}
			j++;
		}
		stack = stack->next;
		i++;
	}
}

// Função pública: indexa a stack
void	bs_index_stack(t_list **stack)
{
	int size;
	int *sorted;

	size = ft_lstsize(*stack);
	sorted = copy_and_sort_stack(*stack, size);
	assign_indices_to_stack(*stack, sorted, size);
	free(sorted);
}
