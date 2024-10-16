/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:18:23 by insoares          #+#    #+#             */
/*   Updated: 2024/10/15 17:55:26 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char* str)
{
	long	numb;
	int		i;
	int		symbol;

	numb = 0;
	i = 0;
	symbol = 1;
	while(str[i] && ((str[i] >= 7 && str[i] <= 13) || str[i] == 32))// passo a fresnte os espacos em banco
		i++;
	if(str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
			symbol *= -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		numb = (numb * 10) + (str[i] - 48);
		i++;
	}
	return(numb * symbol);
}

//Funcao para adicionar numeros `a stack
t_stack_node	*ft_last_node(t_stack_node *head)
{
	t_stack_node *last_node;

	if(!head)
		return(NULL);
	last_node = head;
	while(last_node->next)
		last_node = last_node->next;
	return(last_node);
}

void	attach_to_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;
	
	new_node = malloc(sizeof(t_stack_node));
	if(!new_node)
		return ;
	new_node->next = NULL;
	new_node->number = nbr;
	new_node->has_already_index = false;
	if(*stack == NULL)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = ft_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}
void	ft_get_index(t_stack_node **a)
{
	int 			index;
	int 			size;
	int				smallest;
	t_stack_node	*tmp;

	index = 0;
	size = ft_listsize(*a);
	while (index < size)
	{
		smallest = smallest_number_index(*a);
		if (smallest == -1) // Se não há mais números disponíveis, sai do loop
            break;
		tmp = *a;
		while (tmp)
		{
			if (tmp->number == smallest && !tmp->has_already_index)
			{
				tmp->index = index;
				tmp->has_already_index = true;
				break;// Para evitar atribuir o mesmo índice a múltiplos nós
			}
			tmp = tmp->next;
		}
		index++;
	}
}	
void	stack_init(t_stack_node **a, char **av, bool splited)
{
	int		i;
	long	nbr;

	i = 0;
	while(av[i])
	{
		if(error_syntax(av[i]))
			error_free(a, av, splited);
		nbr = ft_atol(av[i]);
		if(nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, av, splited);
		if(a && error_repetition(a, (int)nbr))
			error_free(a, av, splited);
		attach_to_node(a, (int)nbr);
		i++;
	}
	ft_get_index(a);
}
