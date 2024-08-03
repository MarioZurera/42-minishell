/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:27:18 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/19 17:30:48 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	length;

	length = 0;
	if (n >= 10)
		length = ft_putunbr_fd(n / 10, fd);
	if (length < 0 || ft_putchar_fd((n % 10) + '0', fd) <= 0)
		return (-1);
	return (length + 1);
}
