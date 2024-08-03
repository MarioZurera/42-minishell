/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:52:05 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 21:05:14 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int    ft_count_words(const char *str)
{
    int count;
    
    if (str == NULL)
        return (0);
    count = 0;
    while (*str)
    {
        while (ft_isspace(*str))
            str++;
        if (*str)
            count++;
        while (*str && !ft_isspace(*str))
            str++;
    }
    return (count);
}