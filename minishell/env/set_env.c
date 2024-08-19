/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:54:01 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/19 22:00:01 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	update_env(char *key, char *value)
{
	int		keylen;
	int		i;

	keylen = ft_strlen(key);
	i = 0;
	while (environ && environ[i])
	{
		if (ft_strncmp(environ[i], key, keylen) == 0
			&& environ[i][keylen] == '=')
		{
			free(environ[i]);
			environ[i] = ft_strjoin_sep(key, value, '=');
			return (environ[i] != NULL);
		}
		i++;
	}
	return (0);
}

/**
 * set_env will add a new key-value pair to the environment
 * @return int true if the key was added or updated, false otherwise
 */
int	set_env(char *key, char *value, int ow)
{
	int		update;

	update = getenv(key) != NULL;
	if (!key || !value || (!ow && update))
		return (0);
	if (update)
		return (update_env(key, value));
	else
	{
		//TODO realloc environ when key does not exist, add key=value
		return (0);
	}
}
