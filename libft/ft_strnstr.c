/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:25:35 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/12 19:54:11 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t n)
{
	size_t	i;
	size_t	substr_len;

	substr_len = ft_strlen(substr);
	if (!*substr)
		return ((char *) str);
	if (ft_strlen(str) < substr_len)
		return (NULL);
	i = 0;
	while (str[i] && i + substr_len <= n)
	{
		if (ft_strncmp(&str[i], substr, substr_len) == 0)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
