/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insoares <insoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:08:52 by insoares          #+#    #+#             */
/*   Updated: 2024/10/18 18:00:55 by insoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *str, char separator)
{
	int		counter;
	bool	inside_word;

	counter = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == separator)
			++str;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				++counter;
				inside_word = true;
			}
			++str;
		}
	}
	return (counter);
}

static inline char	*get_next_word(char *str, char separator)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	i = 0;
	len = 0;
	while (str[cursor] == separator)
		cursor++;
	while (str[cursor + len] != separator && str[cursor + len])
		len++;
	next_word = malloc((sizeof(char) * len) + 1);
	if (!next_word)
		return (NULL);
	while (str[cursor] != separator && str[cursor])
	{
		next_word[i] = str[cursor];
		i++;
		cursor++;
	}
	next_word[i] = '\0';
	return (next_word);
}

char	**ft_split_ps(char *str, char separator)
{
	int		nbr_of_words;
	char	**vector_strings;
	int		i;

	i = 0;
	nbr_of_words = count_words(str, separator);
	vector_strings = malloc(sizeof (char *) * (nbr_of_words + 1));
	if (!vector_strings)
		return (NULL);
	while (nbr_of_words-- > 0)
	{
		vector_strings[i] = get_next_word(str, separator);
		if (!vector_strings[i])
		{
			free_split(vector_strings);
			return (NULL);
		}
		i++;
	}
	vector_strings[i] = NULL;
	return (vector_strings);
}
