/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:44:29 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/18 16:32:35 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(void)
{
	char	**new_env;
	int		i;

	i = 0;
	while (environ && environ[i] != NULL)
		i++;
	new_env = ft_calloc(sizeof(char *), (i + 1));
	if (!new_env)
	{
		//TODO panic
		exit(1);
	}
	while (environ && environ[i] != NULL)
	{
		new_env[i] = ft_strdup(environ[i]);
		if (!new_env[i])
		{
			//TODO panic
			exit(1);
		}
		i++;
	}
	environ = new_env;
}
