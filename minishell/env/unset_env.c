/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:40:22 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/08 13:06:44 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * unset_env removes the env entry with the given key
 * and frees the memory allocated for it
 * @return bool true if the entry was found and removed, false otherwise
 */
bool	unset_env(t_env **env, char *key)
{
	t_env	*tmp;
	t_env	*prev;

	if (!key || !env || !*env)
		return (false);
	if (ft_strcmp((*env)->key, key) == 0)
	{
		tmp = *env;
		*env = (*env)->next;
		return (free_entry_env(tmp), true);
	}
	prev = *env;
	tmp = (*env)->next;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->key, key) == 0)
		{
			prev->next = tmp->next;
			return (free_entry_env(tmp), true);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (false);
}
