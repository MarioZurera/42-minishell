/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:36:02 by mzurera-          #+#    #+#             */
/*   Updated: 2023/10/05 19:08:20 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ignore_flags(char *flags)
{
	int	i;

	i = 0;
	while (flags[i] && (!ft_isdigit(flags[i])
			|| flags[i] == '0') && flags[i] != '.' && flags[i] != '*')
		i++;
	return (i);
}

void	add_n(int *n_print, int res)
{
	if (*n_print < 0 || res < 0)
		*n_print = -1;
	else
		*n_print += res;
}

void	print_sign(int d, int *n_print, char *flags)
{
	if (d < 0)
		add_n(n_print, ft_putchar_fd('-', 1));
	else if (ft_strchr(flags, '+') != 0)
		add_n(n_print, ft_putchar_fd('+', 1));
	else if (ft_strchr(flags, ' ') != 0)
		add_n(n_print, ft_putchar_fd(' ', 1));
}

void	print_sign_u(int *n_print, char *flags)
{
	if (ft_strchr(flags, '+') != 0)
		add_n(n_print, ft_putchar_fd('+', 1));
	else if (ft_strchr(flags, ' ') != 0)
		add_n(n_print, ft_putchar_fd(' ', 1));
}

int	has_sign(char *flags)
{
	return (ft_strchr(flags, '+') || ft_strchr(flags, ' '));
}
