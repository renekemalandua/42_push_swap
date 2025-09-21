/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_list_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 23:12:52 by akemalan          #+#    #+#             */
/*   Updated: 2025/08/28 00:25:21 by akemalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_list_last(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

int	ft_list_size(t_list *head)
{
	t_list	*temp;
	int		size;

	size = 0;
	temp = head;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

void	ft_print_list(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp)
	{
		ft_putnbr_fd(temp->data, 1);
		ft_putendl_fd("", 1);
		temp = temp->next;
	}
}
