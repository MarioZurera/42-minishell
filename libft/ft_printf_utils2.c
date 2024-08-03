/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:41:02 by mzurera-          #+#    #+#             */
/*   Updated: 2023/10/05 19:27:39 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_left_padding(int *n_print,
		t_conversion *data, int has_hashtag)
{
	if (ft_strchr(data->flags, '-') == 0 && (ft_strchr(data->flags, '0') == 0
			|| data->precision >= 0))
		add_n(n_print, padding(ft_max(0, data->length
					- *n_print - ft_max(0, data->precision
						- (*n_print - has_hashtag))), ' '));
}

static void	check_right_padding(int *n_print,
		t_conversion *data, unsigned int hex)
{
	if (data->precision >= 0)
		add_n(n_print, padding(ft_max(0, data->precision
					- ft_hexlen(hex)), '0'));
}

int	print_hex(unsigned long int n, char letter)
{
	char	hex;
	int		length;

	length = 0;
	hex = n % 16;
	if (n >= 16)
		length = print_hex(n / 16, letter);
	if (hex < 10)
		hex += '0';
	else
		hex += (letter - 10);
	if (length < 0 || ft_putchar_fd(hex, 1) < 0)
		return (-1);
	return (length + 1);
}

int	eval_hexlow(va_list arg, t_conversion *data)
{
	unsigned int	hex;
	int				n_print;
	int				has_hashtag;

	if (!check_flags(data->flags, "#0-"))
		return (-1);
	hex = va_arg(arg, unsigned int);
	n_print = ft_hexlen(hex);
	if (data->precision == 0 && hex == 0)
		n_print = 0;
	has_hashtag = 2 * (ft_strchr(data->flags, '#') != 0 && hex != 0);
	if (has_hashtag)
		add_n(&n_print, 2);
	check_left_padding(&n_print, data, has_hashtag);
	if (has_hashtag)
		add_n(&n_print, ft_putstr_fd("0x", 1) - 2);
	if (ft_strchr(data->flags, '0') != 0 && data->precision < 0)
		add_n(&n_print, padding(ft_max(0, data->length - n_print), '0'));
	check_right_padding(&n_print, data, hex);
	if (data->precision != 0 || hex != 0)
		add_n(&n_print, print_hex(hex, 'a') - ft_hexlen(hex));
	if (ft_strchr(data->flags, '-') != 0)
		add_n(&n_print, padding(ft_max(0, data->length - n_print), ' '));
	return (n_print);
}

int	eval_hexup(va_list arg, t_conversion *data)
{
	unsigned int	hex;
	int				n_print;
	int				has_hashtag;

	if (!check_flags(data->flags, "#0-"))
		return (-1);
	hex = va_arg(arg, unsigned int);
	n_print = ft_hexlen(hex);
	if (data->precision == 0 && hex == 0)
		n_print = 0;
	has_hashtag = 2 * (ft_strchr(data->flags, '#') != 0 && hex != 0);
	if (has_hashtag)
		add_n(&n_print, 2);
	check_left_padding(&n_print, data, has_hashtag);
	if (has_hashtag)
		add_n(&n_print, ft_putstr_fd("0X", 1) - 2);
	if (ft_strchr(data->flags, '0') != 0 && data->precision < 0)
		add_n(&n_print, padding(ft_max(0, data->length - n_print), '0'));
	check_right_padding(&n_print, data, hex);
	if (data->precision != 0 || hex != 0)
		add_n(&n_print, print_hex(hex, 'A') - ft_hexlen(hex));
	if (ft_strchr(data->flags, '-') != 0)
		add_n(&n_print, padding(ft_max(0, data->length - n_print), ' '));
	return (n_print);
}
