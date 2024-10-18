/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:18:23 by insoares          #+#    #+#             */
/*   Updated: 2024/10/18 16:33:31 by insoares         ###   ########.fr       */
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
	while(str[i] && ((str[i] >= 7 && str[i] <= 13) || str[i] == 32))
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
	new_node->index = -1;
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
	int 			id;
	int 			size;
	int				smallest;
	t_stack_node	*tmp;

	id = -1;
	size = ft_listsize(a);
	while (++id < size)
	{
		tmp = *a;
		smallest = INT_MAX;
		while (tmp)
		{
			if (tmp->number < smallest && tmp->index == -1)
				smallest = tmp->number;
			tmp = tmp->next;
		}
		tmp = *a;
		while(tmp)
		{
			if(tmp->number == smallest && tmp->index == -1)
				tmp->index = id;
			tmp = tmp->next;
		}
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
