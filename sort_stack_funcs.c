/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:16:24 by insoares          #+#    #+#             */
/*   Updated: 2024/10/18 11:11:26 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t		ft_listsize(t_stack_node **stack)
{
	t_stack_node	*temp;
	size_t			s;

	temp = (*stack);
	s = 0;
	if(stack == NULL || *stack == NULL)
		return(0);
	while(temp)
	{
		temp = temp->next;
		s++;
	}
	return(s); 
}

int	smallest_number(t_stack_node *a)
{
	int	smallest;

	smallest = a->number;
	a = a->next;
	while(a != NULL)
	{
		if(a->number < smallest)
			smallest = a->number;
		a = a->next;
	}
	return(smallest);
}

bool	ft_sorted(t_stack_node **stack)
{
	if (stack == NULL || *stack == NULL)
		return (1);
	while((*stack)->next)
	{
		if ((*stack)->number > (*stack)->next->number)
			return (false);
		*stack = (*stack)->next;
	}
	return (true);
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	if(ft_listsize(a) <= 5)
		ft_simple_sort(a, b);
	else
		radix_algorithm(a, b);
}
