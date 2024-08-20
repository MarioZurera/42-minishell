/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:48:03 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/19 18:40:43 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	export(const char *param, t_ms ms)
{
	char **pair;
	int	status;

	if (param == NULL || ft_strchr(param, '=') == NULL)
		return (2);
	pair = ft_split(param, '=');
	if (pair == NULL || pair[0] == NULL || pair[1] == NULL || pair[2] != NULL)
		return (1);
	status = !set_internal(pair[0], pair[1], ms);
	if (status)
		return (status);
	return (!set_env(pair[0], pair[1], 1) == 0);
}