/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:06:27 by insoares          #+#    #+#             */
/*   Updated: 2024/10/14 13:51:12 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//funcao para dar free a matriz criada pelo split
void	ft_free_matrix(char** av)
{
	int	i;
	
	i = 0;
	if(av == NULL || *av == NULL)
		return ;
	while(av[i] && av)
	{
		free(av[i]);
		i++;
	}
	free(av);
}
// Funcao para dar free a uma stack
void	ft_free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*now;

	if(stack == NULL)
		return ;
	now = *stack;
	while(now)
	{
		tmp = now->next;
		free(now);
		now = tmp;
	}
	*stack = NULL;
}
//error se o numero nao e valido
//Esta funcao tem um bool porque se o input for escrti como um str temos de dar free por ter sido aplicado o split
// Caso o input tenha sido colocado "direitinho" o split nao foi usado logo noa temos de dar free a nada 
void	error_free(t_stack_node **a, char **av, bool splited)
{
	ft_free_stack(a);
	if(splited)
		ft_free_matrix(av);
	ft_printf("ERROR");
	exit(1);// encerra a execucao do programa de forma controlada e limpa. 
			//executa funções de término necessárias (fecha arquivos abertos, liberta memória, etc.)
}
//esta funcao verifica se o input esta bem escrito, se se trata de uma nnumero, pode ter um sinbal + ou - antes do numero
int	error_syntax(char *str_nbr)
{
	int	i;

	i = -1;
	while (str_nbr[++i])
	{
		if ((str_nbr[i] != '+' && str_nbr[i] != '-') && (!(str_nbr[i] >= '0' && str_nbr[i] <= '9')))
			return (1);
	}
	return (0);
}

// funcao para verificar se o numero esta repatido na stack
int	error_repetition(t_stack_node **a, int nbr)
{
	t_stack_node *head;
	
	head = *a;
	if(head == NULL || head == NULL)
		return(0);
	while(head)
	{
		if(head->number == nbr)
			return(1);//se o num e repetido retorna 1 (1 representa um erro generico)
		head = head->next;
	}
	return(0);// verifica todos os nodes e se nao tiver nenhum num repetido retorna 0 (segnifica que nao tem erros)
}
