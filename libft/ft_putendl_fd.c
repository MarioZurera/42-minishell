/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:22:18 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/12 19:22:19 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(const char *s, int fd)
{
	int	length;

	length = ft_putstr_fd(s, fd);
	if (length < 0)
		return (-1);
	if (ft_putchar_fd('\n', fd) > 0)
		return (length + 1);
	return (-1);
}
