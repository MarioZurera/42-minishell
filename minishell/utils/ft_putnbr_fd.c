/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:32:26 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/05 19:15:45 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	ln = n;
	if (ln == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln = -ln;
	}
	if (ln > 9)
		ft_putnbr_fd((int)(ln / 10), fd);
	ft_putchar_fd(ln % 10 + '0', fd);
}
