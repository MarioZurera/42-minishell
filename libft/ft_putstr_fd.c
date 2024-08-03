/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:23:00 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/19 16:37:21 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(const char *s, int fd)
{
	int	length;

	length = 0;
	if (s == NULL)
		length = ft_putstr_fd("(null)", fd);
	if (length < 0)
		return (-1);
	while (s && *s)
	{
		if (write(fd, s++, 1) <= 0)
			return (-1);
		length++;
	}
	return (length);
}
