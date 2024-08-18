/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:47:13 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/18 16:29:38 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * free_env will free the memory allocated for the entire env
 */
void	free_env(void)
{
	int	i;

	i = 0;
	while (environ && environ[i] != NULL)
	{
		free(environ[i]);
		i++;
	}
	free(environ);
	environ = NULL;
}
