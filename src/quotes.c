/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 23:17:39 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/04 00:32:25 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Not in use
// This file might check in the future:
// echo '123$HOME' == 123$HOME
// echo "123$HOME" == 123/home/mzurera-

#include "ft_minishell.h"

static bool isescaped(char *line, int index)
{
	if (index == 0)
		return (false);
	return (line[index - 1] == '\\');
}

static bool isquote(char c)
{
	return (c == '\'' || c == '"');
}

string	process_quotes(string line)
{
    int		i;
	int		j;
	bool	has_space;
	char	quote;

	i = 0;
	has_space = false;
	while (line[i])
	{
		if (!quote && isquote(line[i]) && !isescaped(line, i))
		{
			quote = line[i];
			j = i;
		}
		if (quote && isquote(line[i]) && !isescaped(line, i) && line[i] == quote)
		{
			// if (!has_space)
				// remove_quotes();
			(void) j;
			(void) has_space;
			return ("");
		}
		// Unfinished, this idea is more or less done in lexer.c
		// More information under the header of this file.
	}
	return (line);
}