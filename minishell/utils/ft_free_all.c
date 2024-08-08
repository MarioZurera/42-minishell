/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:06:59 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/08 14:57:43 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Free all the pointers passed as arguments
 */
void	ft_free_all(int count, ...)
{
	va_list	args;

	va_start(args, count);
	while (count--)
		free(va_arg(args, void *));
	va_end(args);
}
