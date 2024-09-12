/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:33:15 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/05 19:15:45 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_words(const char *s, char c)
{
	int	words;
	int	in_word;
	int	i;

	words = 0;
	in_word = 0;
	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (!in_word && s[i] != c)
		{
			in_word = 1;
			++words;
		}
		else if (in_word && s[i] == c)
			in_word = 0;
		++i;
	}
	return (words);
}

static void	advance_index_len(char const *s, char c, int *j, int *len)
{
	*len = 0;
	while (s[*j] != '\0' && s[*j] == c)
		*j = *j + 1;
	while (s[*j] != '\0' && s[*j] != c)
	{
		*j = *j + 1;
		*len = *len + 1;
	}
}

static void	*free_everything(char **res, int stop)
{
	int	i;

	i = 0;
	while (i <= stop)
		free(res[i++]);
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		word_count;
	int		len;
	int		i;
	int		j;

	word_count = count_words(s, c);
	res = malloc(sizeof(char *) * (word_count + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < word_count)
	{
		advance_index_len(s, c, &j, &len);
		res[i] = ft_substr(s, j - len, len);
		if (res[i] == NULL)
			return (free_everything(res, i), NULL);
		++i;
	}
	res[word_count] = NULL;
	return (res);
}
