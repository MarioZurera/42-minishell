/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:41:59 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/05 19:15:45 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*p;
	unsigned int	i;

	p = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			p = (char *)s + i;
		++i;
	}
	if ((char)c == 0)
		p = (char *)s + i;
	return (p);
}
