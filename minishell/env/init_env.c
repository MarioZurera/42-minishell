/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:44:29 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/08 10:09:01 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*init_env(char **envp)
{
	t_env	*env;
	char	*eq;
	char	*key;
	char	*value;
	int		i;

	if (!envp)
		return (NULL);
	i = 0;
	env = NULL;
	while (envp[i] != NULL)
	{
		eq = ft_strchr(envp[i], '=');
		key = ft_substr(envp[i], 0, eq - envp[i]);
		value = ft_strdup(eq + 1);
		if (!set_env(&env, key, value))
		{
			free(key);
			free(value);
			free_env(env);
			return (NULL);
		}
		i++;
	}
	return (env);
}
