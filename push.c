/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:27:49 by insoares          #+#    #+#             */
/*   Updated: 2024/10/17 18:00:07 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//tira o elemento de cima de uma stack e colocar no topo da outra stack. 
static void	push(t_stack_node **src, t_stack_node **dest)
{
	t_stack_node *node;// tenho de criar um novo node para transportar da src para a dest
	
	node = *src;//  aqui vou guardar o 1o node da src no novo node
	*src = (*src)->next;// o 1o elemento de srd agora vai ser o seu next
	if(*src)//se existir 2o node na src. se nao existir quem dizer a stack ficou vazia
		(*src)->prev = NULL;// vai passar a apontar agora para null para fazer dele o head da src 
	node->prev = NULL;// o node->prev (novo node que chega ao destino) aponta para null porque torna se o head da stack
	if(*dest == NULL)// se a lista de destino estiver vazia
	{
		*dest = node;// o head da lista passa a ser o novo node
		node->next = NULL;// caracteristica de ultimo node, o seu next aponta para null
	}
	else// se a lista de destino ja tiver nodes
	{
		node->next = *dest;// a posicao seguinte do novo node vai apontar agora para o head do destin
/*e como de tivesse (dest)->prev = node */
		node->next->prev = node;// agora (node->next) e temporariamente o head da dest. quando aponto o seu prev para o novo node deixa de ser head e pass a ser o 2o elemento
		*dest = node;// o head da dest agora passa a ser o novo node
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	ft_printf("pb\n");
}
