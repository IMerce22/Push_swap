/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:08:52 by insoares          #+#    #+#             */
/*   Updated: 2024/09/30 14:03:09 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_words(char *str, char separator)
{
	int	counter;
	bool inside_word;

	counter = 0;
	while(*str)
	{
		inside_word = false;
		while(*str == separator)
			++str;
		while(*str != separator && *str)
		{
			if(!inside_word)
			{
				++counter;
				inside_word = true;
			}
			++str;
		}
	}
	return(counter);
}

static inline char	*get_next_word(char *str, char separator)
{
	static int	cursor = 0;// static porque salva a posicao da palavra anterior, para que da proxima vez que entrar nesta funao consiga perceber quala a proxima palavra 
	char*		next_word;
	int			len;
	int			i;
	
	i = 0;
	len = 0;
	while(str[cursor] == separator)
		cursor++;
	while(str[cursor + len] != separator && str[cursor + len])//so para contar as letras
		len++;
	next_word = malloc((sizeof(char) * len) + 1);// aloquei memoria exata com o n de letras contadas
	if(!next_word)
		return(NULL);
	while(str[cursor] != separator && str[cursor])//o cursor esta em 0, vou copiar a palavra desde o inicio 
	{
		next_word[i] = str[cursor];//processo de copia
		i++;
		cursor++;
	}
	next_word[i] = '\0';// nulo no fim da copia
	return(next_word);
}
char **ft_split_ps(char *str, char separator)
{
	int 	nbr_of_words;
	char	**vector_strings;
	int		i;

	i = 0;
	nbr_of_words = count_words(str, separator);
	vector_strings = malloc(sizeof (char *) * (nbr_of_words + 1));//+2 1 para o placeholder e 1 para o nulo no fim
	if(!vector_strings)
		return(NULL);
	while(nbr_of_words-- > 0)
	{
		vector_strings[i] = get_next_word(str, separator);
		if(!vector_strings[i])
		{
			free_split(vector_strings);
			return(NULL);
		}
		i++;
	}
	vector_strings[i] = NULL;
	return(vector_strings);
}
