/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:49:20 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/22 18:50:38 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *s, int c, int n)
{
	int	i;

	c %= 128;
	i = 0;
	while (s[i] && s[i] != c && i < n)
		++i;
	if (s[i] != c)
		return (NULL);
	return ((char *) &s[i]);
}
