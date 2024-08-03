/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:03:46 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 18:03:22 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_atohex(char *s)
{
	if (s == NULL)
		return (0);
	if (s[0] == '0' && s[1] == 'x')
	{
		s += 2;
		return ((unsigned long) ft_atol_base(s, "0123456789abcdef"));
	}
	if (s[0] == '0' && s[1] == 'X')
	{
		s += 2;
		return ((unsigned long) ft_atol_base(s, "0123456789ABCDEF"));
	}
	return ((unsigned long) ft_atol_base(s, "0123456789ABCDEF"));
}
