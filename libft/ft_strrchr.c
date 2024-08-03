/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:25:43 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/12 19:25:44 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	c %= 128;
	i = ft_strlen(s);
	while (i > 0 && s[i] != c)
		--i;
	if (s[i] != c)
		return (NULL);
	return ((char *)(s + i));
}
