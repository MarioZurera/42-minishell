/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:29:59 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/08 10:58:29 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * last_env returns the last element of the env or NULL if empty
 */
t_env	*last_env(t_env *env)
{
	while (env && env->next)
		env = env->next;
	return (env);
}

/**
 * update_only_env will update the value of the env entry with the given key
 * or do nothing if not found
 * @attention the parameter strings may or may not be allocated,
 * but the function never frees them, copying them if necessary
 */
t_env	*update_only_env(t_env *env, char *key, char *value)
{
	t_env	*tmp;

	tmp = get_env(env, key);
	if (tmp)
	{
		free(tmp->value);
		tmp->value = ft_strdup(value);
	}
	return (env);
}
