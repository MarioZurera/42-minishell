/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:54:01 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/18 20:41:28 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*join_key_value(char *key, char *value)
{
	char	*new_env;
	int		keylen;
	int		valuelen;

	keylen = ft_strlen(key);
	valuelen = ft_strlen(value);
	new_env = malloc(sizeof(char) * (keylen + valuelen + 2));
	if (new_env == NULL)
		return (NULL);
	ft_strlcpy(new_env, key, keylen + 1);
	new_env[keylen] = '=';
	ft_strlcpy(new_env + keylen + 1, value, valuelen + 1);
	return (new_env);
}

/**
 * set_env will add a new key-value pair to the environment
 * @return int true if the key was added or updated, false otherwise
 */
int	set_env(char *key, char *value, int ow)
{
	int		update;
	int		i;

	update = !!getenv(key);
	if (!key || !value || (!ow && update))
		return (0);
	i = 0;
	//TODO not very happy with this implementation
	if (update)
	{
		while (environ && environ[i])
		{
			if (ft_strncmp(environ[i], key, ft_strlen(key)) == 0
				&& environ[i][ft_strlen(key)] == '=')
			{
				free(environ[i]);
				environ[i] = join_key_value(key, value);
				return (1);
			}
			i++;
		}
	}
	//TODO realloc environ when key does not exist, add key=value
}
