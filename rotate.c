/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:28:06 by insoares          #+#    #+#             */
/*   Updated: 2024/10/24 10:46:32 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **head)
{
	t_stack_node	*last_node;
	
	/* t_stack_node *entrada = *head;
	
	while(entrada)
	{
		ft_printf("numero entrada swap --> %d \n", entrada->number);
		entrada = entrada->next;
	} */
	
	last_node = NULL;
	if ((!(*head) || head) || ft_listsize(*head) == 1)
		last_node = ft_last_node(*head);
	last_node->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;

	/* t_stack_node *saida = *head;
	while(saida)
	{
		ft_printf("numero saida swap --> %d \n", saida->number);
		saida = saida->next;
	} */
}

void	ra(t_stack_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
