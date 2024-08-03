/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:56:47 by mzurera-          #+#    #+#             */
/*   Updated: 2023/10/05 19:18:11 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	eval_char(va_list arg, t_conversion *data)
{
	int	n_print;

	n_print = 0;
	if (ft_strlen(data->flags) == 1 && data->flags[0] == '-')
	{
		add_n(&n_print, ft_putchar_fd(va_arg(arg, int), 1));
		add_n(&n_print, padding(ft_max(0, data->length - 1), ' '));
	}
	else if (ft_strlen(data->flags) > 0)
		return (-1);
	else
	{
		add_n(&n_print, padding(ft_max(0, data->length - 1), ' '));
		if (n_print == -1)
			return (-1);
		add_n(&n_print, ft_putchar_fd(va_arg(arg, int), 1));
	}
	return (n_print);
}

int	eval_string(va_list arg, t_conversion *data)
{
	char	*s;
	int		n_print;

	n_print = 0;
	s = (char *) va_arg(arg, const char *);
	if (!check_flags(data->flags, "- "))
		return (-1);
	if (s == NULL)
		s = "(null)";
	if (data->precision >= 0)
		s = ft_substr(s, 0, data->precision);
	if (ft_strchr(data->flags, '-') == 0)
		add_n(&n_print, padding(ft_max(0, data->length - ft_strlen(s)), ' '));
	add_n(&n_print, ft_putstr_fd(s, 1));
	if (ft_strchr(data->flags, '-') != 0)
		add_n(&n_print, padding(ft_max(0, data->length - ft_strlen(s)), ' '));
	if (data->precision >= 0)
		free(s);
	return (n_print);
}

int	eval_pointer(va_list arg, t_conversion *data)
{
	unsigned long	addr;
	int				n_print;

	if (!check_flags(data->flags, "-"))
		return (-1);
	addr = (unsigned long) va_arg(arg, void *);
	n_print = ft_strlen("0x") + ft_hexlen(addr);
	if (ft_strchr(data->flags, '-') == 0)
		add_n(&n_print, padding(ft_max(0, data->length - n_print), ' '));
	add_n(&n_print, ft_putstr_fd("0x", 1) - 2);
	add_n(&n_print, print_hex(addr, 'a') - ft_hexlen(addr));
	if (ft_strchr(data->flags, '-') != 0)
		add_n(&n_print, padding(ft_max(0, data->length - n_print), ' '));
	return (n_print);
}

int	eval_decimal(va_list arg, t_conversion *data)
{
	int	d;
	int	n_print;

	if (!check_flags(data->flags, "-0 +"))
		return (-1);
	d = va_arg(arg, int);
	n_print = ft_unbrlen(ft_abs(d));
	if (data->precision == 0 && d == 0)
		n_print = 0;
	if (ft_strchr(data->flags, '-') == 0 && (ft_strchr(data->flags, '0') == 0
			|| data->precision >= 0))
		add_n(&n_print, padding(ft_max(0, data->length
					- n_print - ft_max(0, data->precision - n_print)
					- (has_sign(data->flags) || (d < 0))), ' '));
	print_sign(d, &n_print, data->flags);
	if (data->precision >= 0)
		add_n(&n_print, padding(ft_max(0, data->precision
					- ft_unbrlen(ft_abs(d))), '0'));
	else if (ft_strchr(data->flags, '0') != 0)
		add_n(&n_print, padding(ft_max(0, data->length - n_print), '0'));
	if (data->precision != 0 || d != 0)
		add_n(&n_print, ft_putunbr_fd(ft_abs(d), 1) - ft_unbrlen(ft_abs(d)));
	if (ft_strchr(data->flags, '-') != 0)
		add_n(&n_print, padding(ft_max(0, data->length - n_print), ' '));
	return (n_print);
}

int	eval_unsigned(va_list arg, t_conversion *data)
{
	unsigned int	u;
	int				n_print;

	if (!check_flags(data->flags, "-0 +"))
		return (-1);
	u = va_arg(arg, unsigned int);
	n_print = ft_unbrlen(u);
	if (data->precision == 0 && u == 0)
		n_print = 0;
	if (ft_strchr(data->flags, '-') == 0 && (ft_strchr(data->flags, '0') == 0
			|| data->precision >= 0))
		add_n(&n_print, padding(ft_max(0, data->length
					- n_print - ft_max(0, data->precision
						- n_print) - has_sign(data->flags)), ' '));
	print_sign_u(&n_print, data->flags);
	if (ft_strchr(data->flags, '0') != 0 && data->precision < 0)
		add_n(&n_print, padding(ft_max(0, data->length - n_print), '0'));
	if (data->precision >= 0)
		add_n(&n_print, padding(ft_max(0, data->precision
					- ft_unbrlen(u)), '0'));
	if (data->precision != 0 || u != 0)
		add_n(&n_print, ft_putunbr_fd(u, 1) - ft_unbrlen(u));
	if (ft_strchr(data->flags, '-') != 0)
		add_n(&n_print, padding(ft_max(0, data->length - n_print), ' '));
	return (n_print);
}
