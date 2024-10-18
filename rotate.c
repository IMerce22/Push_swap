/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:28:06 by insoares          #+#    #+#             */
/*   Updated: 2024/10/17 19:15:54 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **head)
{
	t_stack_node *last_node;

	if(!*head || ft_listsize(head) == 1)// se a stack estiver vazia ou se so existir um elemento na stack (nao e preciso realizar o movimento de rotate)
		return ;
	last_node = ft_last_node(*head);// ha uma funcao para is buscar o ultimo no da lista
	last_node->next = *head; /*antes apontava para NULL*/ // o seguinte do ultimo node passa a ser a head (que passou parao fim da lista)
	*head = (*head)->next;// o inicio da lista passou a ser o que estava a seguir a (*head)
	(*head)->prev = NULL;// o head que era next->head aponta previamente para o NULL para oficializar head
	last_node->next->prev = last_node; // o que era head, como passou para o fim da lista aponta agora previamente para o last_node
	last_node->next->next = NULL; // o seguinte do last node (que era a head mas que passou a ser last, aponta para NULL para oficializar last_node)
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
