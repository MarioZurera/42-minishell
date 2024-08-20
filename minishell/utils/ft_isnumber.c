/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 14:39:22 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/19 19:11:18 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @param s A number is valid if it contains optional sign followed by +1 digits.
 * @return int as a boolean
 */
int	ft_isnumber(const char *s)
{
	if (s == NULL)
		return (0);
	if (s[0] == '-' || s[0] == '+')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}
