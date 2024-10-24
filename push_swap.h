/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:40:00 by insoares          #+#    #+#             */
/*   Updated: 2024/10/24 11:02:28 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stddef.h>
# include "libft/libft.h"
# include "libft/extra/ft_printf/ft_printf.h"

/* ESTRUTURA DOS NODES */
typedef struct s_stack_node
{
	int					number;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//-------------------------------error_free_funcs.2.c
void			free_split(char **split);
t_stack_node	**ft_firstnode(t_stack_node **stack);

//-------------------------------error_free_funcs.c
void			ft_free_stack(t_stack_node **stack);
int				error_syntax(char *str_nbr);
void			error_free(t_stack_node **a, char **av, bool splited);
int				error_repetition(t_stack_node **a, int nbr);

//------------------------------ft_split_ps.c
/* static char		*get_next_word(char *str, char separator); */
char			**ft_split_ps(char *str, char separator);
int				count_words(char *str, char separator);

// ----------------------------- main.c
void			build_the_stack(int ac, char **av, t_stack_node **a);

// ----------------------------stack_init.c
/*long		ft_atol(const char* str); */
t_stack_node	*ft_last_node(t_stack_node *head);
void			attach_to_node(t_stack_node **stack, int nbr);
void			ft_get_index(t_stack_node **a);
void			stack_init(t_stack_node **a, char **av, bool splited);

// --------------------------- comando PUSH
/* static void		push(t_stack_node *src, t_stack_node *dest); */
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);

// -------------------------- comando SWAP
/*void		swap(t_stack_node *head); */
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

// -------------------------- comando ROTATE
/* static void		rotate(t_stack_node *head); */
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

// -------------------------- comando REVERSE_ROTATE
/* static void		reverse_rotate(t_stack_node *head); */
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

//-----------------------------sort_stack_funcs.c
size_t			ft_listsize(t_stack_node *stack);
int				smallest_number(t_stack_node *a);
bool			ft_sorted(t_stack_node *stack);
void			sort_stack(t_stack_node **a, t_stack_node **b);

// -------------------------- simple_sort.c
void			ft_sort_3(t_stack_node **a);
void			ft_sort_4_and_5(t_stack_node **a, t_stack_node **b);
int				which_rotation(t_stack_node *a);
void			ft_simple_sort(t_stack_node **a, t_stack_node **b);

// --------------------------- radix.c
int				biggest_numbr(t_stack_node *a);
int				ft_max_bits(t_stack_node **stack);
void			radix_algorithm(t_stack_node **a, t_stack_node **b);

#endif