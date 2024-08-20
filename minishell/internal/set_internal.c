/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_internal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:44:29 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/18 16:32:35 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	push_key(const char *key, const char *value, t_ms *ms)
{
	int		size;
	char	***new_internals;

	size = 0;
	while (ms->internals[size] != NULL)
		size++;
	new_internals = malloc(sizeof(char **) * (size + 2));
	if (!new_internals)
		return (0);
	size = 0;
	while (ms->internals[size] != NULL)
		new_internals[size++] = ms->internals[size];
	new_internals[size] = malloc(sizeof(char *) * 3);
	if (!new_internals[size])
		return (0);
	new_internals[size][0] = ft_strdup(key);
	new_internals[size][1] = ft_strdup(value);
	if (!new_internals[size][0] || !new_internals[size][1])
	new_internals[size][2] = NULL;
	new_internals[size + 1] = NULL;
	free(ms->internals);
	ms->internals = new_internals;
	return (1);
}

static int	update_internal(const char *key, const char *value, t_ms *ms)
{
	int		keylen;
	int		i;

	keylen = len(key);
	i = 0;
	while (ms->internals && ms->internals[i])
	{
		if (ft_strncmp(ms->internals[i][0], key, keylen) == 0)
		{
			free(ms->internals[i][1]);
			ms->internals[i][1] = ft_strdup(value);
			return (ms->internals[i][1] != NULL);
		}
		i++;
	}
	return (0);
}

/**
 * set_internal will add a new key-value pair to the internal variables
 * @return int true if the key was added or updated, false otherwise
 */
int	set_internal(const char *key, const char *value, t_ms *ms)
{

	if (key == NULL || value == NULL || key[0] == '\0' || value[0] == '\0')
		return (0);
	if (get_internal(key, ms) != NULL)
		return (update_internal(key, value, ms));
	return (push_key(key, value, ms));
}
