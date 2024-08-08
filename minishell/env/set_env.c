/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:54:01 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/08 13:05:29 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * set_env will add a new key-value pair to the environment
 * @return bool true if the key was added or updated, false otherwise
 */
bool	set_env(t_env **env, char *key, char *value)
{
	t_env	*new;
	t_env	*tmp;

	tmp = get_env(*env, key);
	if (tmp != NULL)
	{
		free(tmp->value);
		tmp->value = value;
		free(key);
		return (true);
	}
	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (false);
	new->key = key;
	new->value = value;
	new->next = NULL;
	if (!*env)
	{
		*env = new;
		return (true);
	}
	tmp = last_env(*env);
	tmp->next = new;
	return (true);
}
