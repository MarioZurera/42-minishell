/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequote.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 13:12:54 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/04 17:30:20 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	dequoted_len(char *str);
static void	dequoted_copy(char *dq, char *str);

/**
 * Removes first level of quotes from a string.
 * Quotes can be single or double quotes.
 * Quotes within different quotes are not removed. Examples:
 * "echo" returns echo
 * e"c"h"o" returns echo
 * "a'b'c" returns a'b'c
 * 'a"b"c' returns a"b"c
 */
char	*dequote(char *str)
{
	int		len;
	char	*dq;

	len = dequoted_len(str);
	if (len == 0)
		return (ft_strdup(""));
	dq = malloc(len + 1);
	if (dq == NULL)
		return (NULL);
	dequoted_copy(dq, str);
	return (dq);
}

/**
 * Returns the length of a string without the first level of quotes.
 */
static int	dequoted_len(char *str)
{
	int		len;
	int		i;
	char	quote;

	(0) || (len = 0) || (i = 0) || (quote = 0);
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			quote = str[i++];
			while (str[i] && str[i] != quote)
				(void)((++i) && (++len));
		}
		else
			len++;
		i++;
	}
	return (len);
}

/**
 * Copies a string without the first level of quotes.
 */
static void	dequoted_copy(char *dq, char *str)
{
	int		i;
	int		j;
	char	quote;

	(0) || (i = 0) || (j = 0) || (quote = 0);
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			quote = str[i++];
			while (str[i] && str[i] != quote)
				dq[j++] = str[i++];
		}
		else
			dq[j++] = str[i];
		i++;
	}
	dq[j] = '\0';
}
