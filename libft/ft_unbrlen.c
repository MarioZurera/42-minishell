/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:22:43 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/18 19:30:08 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unbrlen(unsigned int n)
{
	int	length;

	length = 0;
	if (n == 0)
		++length;
	while (n > 0)
	{
		n /= 10;
		++length;
	}
	return (length);
}
