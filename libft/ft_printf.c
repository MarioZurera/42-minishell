/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:56:15 by mzurera-          #+#    #+#             */
/*   Updated: 2023/10/05 19:12:39 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_flags(const char *format, int *pos)
{
	char	*flags;
	char	*conversions;
	int		start;
	char	*result;

	conversions = "cspdiuxX%";
	flags = "-0# +";
	start = *pos;
	while (ft_strchr(flags, format[*pos]))
		(*pos)++;
	while (ft_isdigit(format[*pos]))
		(*pos)++;
	if (format[*pos] == '.' || format[*pos] == '*')
		(*pos)++;
	while (ft_isdigit(format[*pos]))
		(*pos)++;
	if (format[*pos] == '*')
		(*pos)++;
	if (!ft_strchr(conversions, format[*pos]))
		return (NULL);
	result = ft_substr(format, start, *pos - start);
	if (result == NULL)
		return (NULL);
	return (result);
}

static void	format_flags(t_conversion *data, va_list arg)
{
	int		i;
	int		j;
	char	*flg;

	i = 0;
	j = 0;
	flg = data->flags;
	while (flg[i])
	{
		if (flg[i] == '*' || ft_isdigit(flg[i])
			|| j == 0 || !ft_strnchr(flg, flg[i], j - 1))
		{
			flg[j] = flg[i];
			j++;
		}
		i++;
	}
	flg[j] = '\0';
	get_lengths(flg, arg, &data->length, &data->precision);
	if (ft_strchr(flg, '0') && ft_strchr(flg, '-'))
		ft_strdelchr(flg, '0');
	if (ft_strchr(flg, ' ') && ft_strchr(flg, '+'))
		ft_strdelchr(flg, ' ');
}

static t_conversion	*eval_flags(const char *format, int *pos, va_list arg)
{
	t_conversion	*data;

	data = (t_conversion *) malloc(sizeof(t_conversion));
	if (data == NULL)
		return (NULL);
	data->length = 0;
	data->precision = -1;
	data->flags = get_flags(format, pos);
	if (data->flags == NULL)
	{
		free(data);
		return (NULL);
	}
	format_flags(data, arg);
	return (data);
}

int	eval_conversion(const char *format, int *pos, va_list arg)
{
	int				printed_chars;
	t_conversion	*data;

	printed_chars = 0;
	data = eval_flags(format, pos, arg);
	if (data == NULL)
		return (-1);
	printed_chars = ft_conversion(format, pos, arg, data);
	free(data->flags);
	free(data);
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		printed_chars;
	int		pos;
	int		temp;

	va_start(arg, format);
	printed_chars = 0;
	pos = 0;
	while (format[pos] && printed_chars >= 0)
	{
		if (format[pos] == '%')
		{
			++pos;
			temp = eval_conversion(format, &pos, arg);
		}
		else
			temp = ft_putchar_fd(format[pos], 1);
		printed_chars += temp;
		if (temp < 0)
			printed_chars = -1;
		++pos;
	}
	va_end(arg);
	return (printed_chars);
}
