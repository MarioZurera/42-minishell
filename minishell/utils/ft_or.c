/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:31:39 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/08 21:50:40 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * ft_or returns the first non NULL string
 */
char	*ft_or(char *s1, char *s2)
{
	if (s1)
		return (s1);
	return (s2);
}
