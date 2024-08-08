/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:47:13 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/08 10:16:36 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * free_entry_env will free the memory allocated for a single entry in the env
 */
void	free_entry_env(t_env *env)
{
	free(env->key);
	free(env->value);
	free(env);
}

/**
 * free_env will free the memory allocated for the entire env
 */
void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env;
		env = env->next;
		free_entry_env(tmp);
	}
}
