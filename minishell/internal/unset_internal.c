/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_internal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:44:29 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/18 16:32:35 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * unset_internal removes the internal entry with the given key
 * and frees the memory allocated for it
 * @return int true if the entry was found and removed, false otherwise
 */
int	unset_internal(const char *key, t_ms *ms)
{
	int		i;
	int		j;
	int		keylen;
	int		internal_len;
	char	***new_internal;

	if (!key || get_internal(key, ms) == NULL)
		return (0);
	keylen = len(key);
	internal_len = 0;
	while (ms->internals && ms->internals[internal_len])
		++internal_len;
	new_internal = malloc(internal_len * sizeof(char **));
	if (new_internal == NULL)
		return (0);
	i = 0;
	j = 0;
	while (ms->internals && ms->internals[j])
	{
		if (ft_strncmp(ms->internals[j][0], key, keylen) != 0)
			new_internal[i++] = ms->internals[j];
		else
			free(ms->internals[j]);
		++j;
	}
	new_internal[i] = NULL;
	free(ms->internals);
	ms->internals = new_internal;
	return (1);
}
