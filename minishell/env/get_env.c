/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:41:54 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/08 11:32:44 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * get_env returns the env entry with the given key
 * or NULL if not found
 */
t_env	*get_env(t_env *env, char *key)
{
	if (!key)
		return (NULL);
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

/**
 * get_env_value returns the value of the env entry with the given key
 * or NULL if not found
 */
char	*get_env_value(t_env *env, char *key)
{
	t_env	*tmp;

	tmp = get_env(env, key);
	if (tmp)
		return (tmp->value);
	return (NULL);
}
