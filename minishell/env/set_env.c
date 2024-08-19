/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:54:01 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/19 18:55:55 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * set_env will add a new key-value pair to the environment
 * @return int true if the key was added or updated, false otherwise
 */
int	set_env(char *key, char *value, int ow)
{
	int		update;
	int		i;

	update = getenv(key) != NULL;
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
