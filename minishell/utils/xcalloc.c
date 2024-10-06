/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xcalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:57:29 by aflorido          #+#    #+#             */
/*   Updated: 2024/10/06 18:01:29 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * calloc with error handling (exit on failure)
 */
void	*xcalloc(size_t size)
{
	void	*ptr;

	ptr = xmalloc(size);
	ft_bzero(ptr, size);
	return (ptr);
}
