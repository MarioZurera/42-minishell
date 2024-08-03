/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:31:55 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/12 19:47:16 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrcpy(void *dest, const void *src, size_t n)
{
	char	*c_dest;
	char	*c_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	c_dest = (char *) dest;
	c_src = (char *) src;
	while (n--)
		c_dest[n] = c_src[n];
	return (dest);
}
