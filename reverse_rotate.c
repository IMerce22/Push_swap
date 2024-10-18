/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:54:31 by insoares          #+#    #+#             */
/*   Updated: 2024/10/17 19:16:06 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack_node **head)
{
	t_stack_node *last_node;

	if(!*head || ft_listsize(head) == 1)
		return ;
	last_node = ft_last_node(*head);
	last_node->prev->next = NULL; //o seguinte do node antes do ultimo passa a apontar next para NULL para oficializar last_node
	last_node->next = *head;
	last_node->prev = NULL; // o last_node passa a ser o 10, logo o seu prev passa  a ser null
	last_node->next->prev = last_node;
}

void		rra(t_stack_node **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void		rrb(t_stack_node **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void		rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
