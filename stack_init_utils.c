/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:54:56 by insoares          #+#    #+#             */
/*   Updated: 2024/10/15 17:55:46 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int smallest_number_index(t_stack_node *a)
{
    int		smallest; // Inicializa com o maior valor possível
    bool	found; // Para verificar se encontramos um número válido

	smallest = INT_MAX;
	found = false;
    while (a != NULL)
    {
        if (!a->has_already_index) // Ignora nós que já têm índice
        {
            found = true;
            if (a->number < smallest)
                smallest = a->number;
        }
        a = a->next;
    }
    if (!found)
        return -1; // Ou qualquer valor que indique que não há números disponíveis

    return (smallest);
}