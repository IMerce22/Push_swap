/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:28:43 by insoares          #+#    #+#             */
/*   Updated: 2024/10/08 15:25:08 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//trocas os dois elementos de cima deuma stack
static void	swap(t_stack_node *head)
{
	if(head == NULL || ft_listsize(head) == 1)
		return ;
	/*mudo de lugar os dois 1os elementos*/ 
	head = head->next;// o 1o node(ou head) e o que era o head->next
	//reajusto as ligacoes do 1o node original (na perspetiva do 2o node era o head->prev)
	head->prev->prev = head;/*e nao NULL*/ // POV do 2o node, que agora e head. "o que era o meu head->prev(1o node) o seu prev agora sou eu. logo head->prev->prev = head"
	head->prev->next = head->next;/*e nao head*/ // o next do que era o 1o passa a ser o que era o 3o node
	//reajusto as ligacoes do 2o node original(o 2o node original e a head agora)
	//caso o 2o node original tenha next(3o node)
	if(head->next)
		head->next->prev = head->prev;// o prev do 3o node passa a ser o que estava antes de mim (POV 2o node original - o seu prev era o 1o)
	head->next = head->prev;// POV 2o node original: o ,eu seguinte passa a ver o que era  meu prev (1o node)
	head->prev = NULL;// para eu ser a head o meu prev tem de ser null
}

void sa(t_stack_node *a)
{
	swap(a);
	ft_printf("sa\n");
}
void sb(t_stack_node *b)
{
	swap(b);
	ft_printf("sb\n");
}
void ss(t_stack_node *a, t_stack_node *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
