/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_internal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:44:29 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/18 16:32:35 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_internal(const char *key, t_ms *ms)
{
	char	*value;

	value = get_internal(key, ms);
	if (value == NULL)
		return (0);
	value[0] = '\0';
	return (1);
}