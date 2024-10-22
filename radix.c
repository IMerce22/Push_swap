/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:13:39 by insoares          #+#    #+#             */
/*   Updated: 2024/10/22 11:18:08 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest_numbr(t_stack_node *a)
{
	int	biggest;

	biggest = INT_MIN;
	a = a->next;
	while (a != NULL)
	{
		if (a->number > biggest)
			biggest = a->number;
		a = a->next;
	}
	return (biggest);
}

int	ft_max_bits(t_stack_node **stack)
{
	t_stack_node	*head;
	int				max;
	int				max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head != NULL)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_algorithm(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*head;
	int				i;
	int				j;
	int				size;
	int				max_bits;

	i = -1;
	head = *a;
	size = ft_listsize(head);
	max_bits = ft_max_bits(a);
	while (++i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head = *a;
			if (((head->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (ft_listsize(*b))
			pa(a, b);
	}
}
