/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:27:20 by mzurera-          #+#    #+#             */
/*   Updated: 2023/10/03 20:22:48 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	eval_percentage(t_conversion *data)
{
	int	n_print;

	n_print = 0;
	if (ft_strlen(data->flags) == 1 && data->flags[0] == '-')
	{
		add_n(&n_print, ft_putchar_fd('%', 1));
		add_n(&n_print, padding(ft_max(0, data->length - 1), ' '));
	}
	else if (ft_strlen(data->flags) == 1 && data->flags[0] == '0')
	{
		add_n(&n_print, padding(ft_max(0, data->length - 1), ' '));
		add_n(&n_print, ft_putchar_fd('%', 1));
	}
	else if (ft_strlen(data->flags))
		return (-1);
	else
	{
		add_n(&n_print, padding(ft_max(0, data->length - 1), ' '));
		add_n(&n_print, ft_putchar_fd('%', 1));
	}
	return (n_print);
}
