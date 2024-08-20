/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_internal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:44:29 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/18 16:32:35 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @return char * a reference to the pointer containing value, NULL otherwise
 */
char	*get_internal(const char *key, t_ms *ms)
{
	int	i;
	int	keylen;

	i = 0;
	keylen = len(key);
	if (ms == NULL || key == NULL || keylen == 0 || ms->internals == NULL)
		return (NULL);
	while (ms->internals[i] && ms->internals[i][0])
		if (ft_strncmp(ms->internals[i][0], key, keylen) == 0)
			return (ms->internals[i][1]);
	return (NULL);
}
