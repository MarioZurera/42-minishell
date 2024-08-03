/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:57:47 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 17:58:48 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strncontains(char *str, char c, int n)
{
	int	i;

	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] == c)
			return (1);
		++i;
	}
	return (0);
}

static int	ft_find_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && c != str[i])
		++i;
	return (i);
}

static int	process_base(char *base, int *length)
{
	*length = 0;
	while (base[*length])
	{
		if (base[*length] == '+' || base[*length] == '-')
			return (0);
		if (ft_strncontains(base, base[*length], *length))
			return (0);
		++(*length);
	}
	return (*length > 1);
}

static int	get_number(char *str, char *base, int i)
{
	int	number;
	int	base_size;
	int	pos;

	if (!(process_base(base, &base_size)))
		return (0);
	number = 0;
	pos = ft_find_char(base, str[i]);
	while (pos != base_size)
	{
		number += pos;
		++i;
		pos = ft_find_char(base, str[i]);
		if (pos != base_size)
			number *= base_size;
	}
	return (number);
}

long	ft_atol_base(char *str, char *base)
{
	long			number;
	char			sign;
	int				i;

	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		++i;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		++i;
	}
	number = get_number(str, base, i);
	return (number * sign);
}
