/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 14:39:22 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/19 19:06:45 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @param str A number is valid if it contains optional sign followed by +1 digits.
 * @return int as a boolean
 */
int	ft_isnumber(const char *str)
{
	if (str == NULL)
		return ((unsigned long long int)(int) NULL);
	if (str[0] == '-' || str[0] == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
