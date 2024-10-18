/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:54:41 by insoares          #+#    #+#             */
/*   Updated: 2024/10/18 11:09:45 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack_node **a)
{
	t_stack_node *tmp;
	
	tmp = *a;
	if(ft_sorted(&tmp))
		return ;
	while(!(ft_sorted(&tmp)))//nquanto nao estiver organizado
	{
		if(tmp->number > tmp->next->number)
			sa(&tmp);
		else
			rra(&tmp);
	}
}
void	ft_sort_4_and_5(t_stack_node **a, t_stack_node **b)
{
	int	smallest;
	int	rotation;

	smallest = smallest_number(*a);
	rotation = which_rotation(a);
	while(ft_listsize(a) > 3)// a lista ira ter entre 4 a 5 numeros
	{	// comeca a percorrer a lista e compara cada numero com o menor 
		// numero que foi encontrado atraves da funcao 
		while((*a)->number != smallest)
		{
			if(rotation == 1)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
	}
	ft_sort_3(a);
	while(ft_listsize(b) >= 1)
		pa(a, b);
}
// esta funcao permitenos sabem em que index esta localizado o numero mais pequeno 
//para perceber se nos compensa mais fazer uma rotate ou uma revers_rotate para ter 
//o menor numero em cima para fazer push para b e assim fazer a sort of 3
int	which_rotation(t_stack_node **a)
{
	int	smallest;
	int	index;
	int index_of_the_smallest;
	int	size;

	smallest = INT_MAX;
	index = 0;
	index_of_the_smallest = 0;
	size = (ft_listsize(a) / 2);//para nos localizarmos exatamente a meio da lista
	//este loop vai procurar o numero mais pequeno na lista de 4 numeros e diz nos 
	//exatamente qual o seu index
	while(*a)
	{
		if((*a)->number < smallest)
		{
			smallest = (*a)->number;
			index_of_the_smallest = index;
		}
		(*a) = (*a)->next;
		index++;
	}
	if(index_of_the_smallest < size)
		return(1);
	else
		return(-1);
}
void	ft_simple_sort(t_stack_node **a, t_stack_node **b)
{
	int size;

	size = ft_listsize(a);
	if(ft_sorted(a) || size == 0 || size == 1)
		return ;
	if(size == 2)
		sa(a);
	else if(size == 3)
		ft_sort_3(a);
	else if(size == 4 || size == 5)
		ft_sort_4_and_5(a, b);
}