/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:21:42 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/12 19:21:43 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*memory1;
	const unsigned char	*memory2;
	size_t				i;

	if (n == 0)
		return (0);
	memory1 = (const unsigned char *) s1;
	memory2 = (const unsigned char *) s2;
	i = 0;
	while (i < n - 1 && memory1[i] == memory2[i])
		++i;
	return (memory1[i] - memory2[i]);
}
