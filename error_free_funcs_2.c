/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free_funcs_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:42:11 by insoares          #+#    #+#             */
/*   Updated: 2024/10/18 18:09:09 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free (split);
}

t_stack_node	**ft_firstnode(t_stack_node **stack)
{
	t_stack_node	**first_node;

	if (!stack || !*stack)
		return (NULL);
	first_node = stack;
	if ((*first_node)->prev != NULL)
		(*first_node) = (*first_node)->prev;
	return (first_node);
}
