/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_internal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:47:13 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/19 22:18:01 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
	* free_internal will free the memory allocated for the entire internal
*/
void	free_internal(t_ms *ms)
{
	int	i;
	int	j;

	i = 0;
	while (ms->internals && ms->internals[i] != NULL)
	{
		j = 0;
		while (ms->internals[i][j] != NULL)
			free(ms->internals[i][j++]);
		free(ms->internals[i]);
		i++;
	}
	free(ms->internals);
	ms->internals = NULL;
}
