/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:24:17 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/12 19:24:18 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	cat_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (size + src_len);
	if (dest_len + src_len < size)
		cat_len = src_len;
	else
		cat_len = size - dest_len - 1;
	ft_memcpy(dest + dest_len, src, cat_len);
	dest[dest_len + cat_len] = '\0';
	return (dest_len + src_len);
}
