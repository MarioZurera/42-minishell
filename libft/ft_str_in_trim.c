/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_in_trim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:39:38 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/23 19:43:28 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_in_trim(char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		++i;
	while (j > i && ft_strchr(set, s1[j]))
		--j;
	k = 0;
	while (i < j + 1)
	{
		s1[k] = s1[i];
		++i;
		++k;
	}
	s1[k] = '\0';
	return (s1);
}
