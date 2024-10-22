/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:06:27 by insoares          #+#    #+#             */
/*   Updated: 2024/10/22 18:07:44 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_matrix(char **av)
{
	int	i;

	i = 0;
	if (av == NULL || *av == NULL)
		return ;
	while (av[i] && av)
	{
		free(av[i]);
		i++;
	}
	free (av);
}

void	ft_free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*now;

	if (!stack || !*stack)
		return ;
	now = *stack;
	while (now)
	{
		tmp = now->next;
		free(now);
		now = tmp;
	}
	*stack = NULL;
}

void	error_free(t_stack_node **a, char **av, bool splited)
{
	ft_free_stack(a);
	if (splited)
		ft_free_matrix(av);
	ft_printf("ERROR\n");
	exit(1);
}

int	error_syntax(char *str_nbr)
{
	int	i;

	i = -1;
	while (str_nbr[++i])
	{
		if ((str_nbr[i] != '+' && str_nbr[i] != '-')
			&& (!(str_nbr[i] >= '0' && str_nbr[i] <= '9')))
			return (1);
	}
	return (0);
}

int	error_repetition(t_stack_node **a, int nbr)
{
	t_stack_node	*head;

	head = *a;
	if (head == NULL || head == NULL)
		return (0);
	while (head)
	{
		if (head->number == nbr)
			return (1);
		head = head->next;
	}
	return (0);
}
