/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:46:40 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/05 19:15:45 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	calculate_valid_range(int *first, int *last,
	char const *s1, char const *set)
{
	int	i;

	*first = -1;
	*last = -1;
	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]) == NULL)
		{
			if (*first == -1)
				*first = i;
			*last = i;
		}
		++i;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		first_char;
	int		last_char;
	int		len;

	calculate_valid_range(&first_char, &last_char, s1, set);
	if (first_char == -1)
		return (ft_strdup(""));
	len = last_char - first_char + 1;
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s1[first_char + i];
		++i;
	}
	res[i] = '\0';
	return (res);
}
