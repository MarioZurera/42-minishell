/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:49:37 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/05 19:15:45 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

inline size_t	len(const char *s)
{
	static t_len	cache[6];
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 6)
	{
		if (cache[i].str == s)
			return (cache[i].len);
		if (cache[i].str == NULL)
			j = i;
		i++;
	}
	cache[j].str = s;
	cache[j].len = ft_strlen(s);
	cache[(j + 1) % 6].str = NULL;
	return (cache[j].len);
}
