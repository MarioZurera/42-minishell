/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:48:03 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/19 18:40:43 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set(t_ms *ms)
{
	char	***setp;

	setp = ms->internals;
	if (!setp)
		return (1);
	while (setp)
	{
		printf("%s", (*setp)[0]);
		printf("=");
		printf("%s\n", (*setp)[1]);
		++setp;
	}
	return (0);
}


int	set(const char **argv, t_ms *ms)
{
	if (argv == NULL || argv[0] == NULL || argv[1] == NULL || argv[2] == NULL || argv[3] != NULL)
		return (set(ms));
	if (argv[1][0] == '\0' || argv[2][0] == '\0')
		return (set(ms));
	return (!set_internal(argv[0], argv[1], ms));
}