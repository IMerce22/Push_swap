/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:29:42 by insoares          #+#    #+#             */
/*   Updated: 2024/10/24 11:02:48 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	build_the_stack(int ac, char **av, t_stack_node **a)
{
	char	**matrix;

	if (ac == 2)
	{
		matrix = ft_split_ps(av[1], ' ');
		stack_init(a, matrix, true);
		free_split(matrix);
	}
	else
		stack_init(a, av + 1, false);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && (!av[1][0])))
		return (-1);
	build_the_stack (ac, av, &a);
	if (ft_sorted(a) == true)
	{
		ft_free_stack(&a);
		ft_free_stack(&b);
		return (0);
	}
	else if (ft_sorted(a) == false)
	{
		sort_stack(&a, &b);
		ft_free_stack(&a);
		ft_free_stack(&b);
	}
	return (0);
}
