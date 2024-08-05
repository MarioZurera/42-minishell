/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:24:32 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/05 19:15:45 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	num_length(int n)
{
	int		len;
	long	copy;

	if (n == 0)
		return (1);
	len = 0;
	copy = n;
	if (copy < 0)
	{
		++len;
		copy = -copy;
	}
	while (copy > 0)
	{
		copy /= 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*a;
	long	copy;
	int		len;

	len = num_length(n);
	a = malloc(sizeof(char) * (len + 1));
	if (a == NULL)
		return (NULL);
	copy = n;
	if (copy == 0)
		a[0] = '0';
	if (copy < 0)
	{
		a[0] = '-';
		copy = -copy;
	}
	a[len--] = '\0';
	while (copy > 0)
	{
		a[len--] = copy % 10 + '0';
		copy /= 10;
	}
	return (a);
}
