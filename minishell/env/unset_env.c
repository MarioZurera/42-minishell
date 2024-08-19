/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:40:22 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/19 17:20:18 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * unset_env removes the env entry with the given key
 * and frees the memory allocated for it
 * @return int true if the entry was found and removed, false otherwise
 */
int	unset_env(char *key)
{
	int		i;
	int		envlen;
	int		keylen;
	char	**new_env;

	if (!key || !getenv(key))
		return (0);
	keylen = ft_strlen(key);
	envlen = 0;
	while (environ && environ[envlen])
		envlen++;
	new_env = ft_calloc(envlen, sizeof(char *));
	if (!new_env)
		return (0);
	i = 0;
	while (environ && environ[i])
	{
		if (ft_strncmp(environ[i], key, keylen) != 0
				|| environ[i][keylen] != '=')
			new_env[i] = environ[i];
		else
			free(environ[i]);
		i++;
	}
	free(environ);
	environ = new_env;
	return (1);
}
