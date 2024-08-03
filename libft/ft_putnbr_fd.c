/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:22:46 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/12 19:22:47 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	recursive_putnbr_fd(int n, int fd)
{
	int	length;

	length = 0;
	if (n <= -10 || n >= 10)
		length = recursive_putnbr_fd(n / 10, fd);
	if (length < 0)
		return (-1);
	if (n < 0)
		length += ft_putchar_fd(((n % 10) * -1) + '0', fd);
	else
		length += ft_putchar_fd((n % 10) + '0', fd);
	return (length);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	length;

	length = 0;
	if (n < 0)
		length += ft_putchar_fd('-', fd);
	if (length < 0)
		return (-1);
	length += recursive_putnbr_fd(n, fd);
	if (length <= 0)
		return (-1);
	return (length);
}
