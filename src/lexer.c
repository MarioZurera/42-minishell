/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 23:17:41 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/04 01:34:36 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

// Lexer without quotes implemented.

static int	isoperator(const string line, int index)
{
	string	operators[] = { "<", "<<", ">", ">>", "|", "&&", "||", NULL };
	int		i;
	int		len;
	
	i = 0;
	while (operators[i])
	{
		len = ft_strlen(operators[i]);
		if (ft_strncmp(line + index, operators[i], len) == 0)
			return (len);
		i++;
	}
	return (0);
	
}

static int	ft_count_tokens(const string line)
{
	int		i;
	int		op_len;
	int		count;
	bool	new_word;
	
	i = 0;
	count = 0;
	new_word = true;
	while (line[i])
	{
		op_len = isoperator(line, i);
		if (op_len)
		{
			count++;
			i += op_len;
			new_word = 1;
		}
		else if (line[i] && !isspace(line[i]) && new_word)
		{
			count++;
			i++;
			new_word = false;
		}
		else if (isspace(line[i]))
			new_word = true;
		else
			i++;
	}
	return (count);
}

t_token	*tokenize(string line)
{
	int		i;
	int		j;
	int		index;
	int		op_len;
	t_token	*tokens;

	ft_str_in_trim(line, " \n\v\f\t\r");
	tokens = malloc((ft_count_tokens(line) + 1) * sizeof(t_token));
	if (tokens == NULL)
		return (NULL);
	index = 0;
	i = 0;
	j = -1;
	while (line[i])
	{
		op_len = isoperator(line, i);
		if (op_len)
		{
			if (j < 0)
			{
				tokens[index].op = WORD;
				tokens[index++].value = ft_substr(line, j, i - j);
			}
			tokens[index].op = OPERATOR;
			tokens[index++].value = ft_substr(line, i, op_len);
			i += op_len;
			j = -1;
		}
		else if (line[i] && !isspace(line[i]))
		{
			if (j < 0)
				j = i;
			i++;
			
		}
		else
		{
			tokens[index].op = WORD;
			tokens[index++].value = ft_substr(line, j, i - j);
			j = -1;
			i++;
		}
	}
	return (tokens);
}