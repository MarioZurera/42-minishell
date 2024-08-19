/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:20:41 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/19 18:20:47 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Joins two strings with a separator, does not free or modify the input
 * @param key the first string
 * @param value the second string
 * @param sep the separator, please don't use '\0'
 * @return the malloc'ed new string
 */
char    *ft_strjoin_sep(char *key, char *value, char sep)
{
    char    *new_entry;
    int     keylen;
    int     vallen;

    keylen = ft_strlen(key);
    vallen = ft_strlen(value);
    new_entry = malloc(sizeof(char) * (keylen + vallen + 2));
    if (new_entry == NULL)
        return (NULL);
    ft_strcpy(new_entry, key);
    new_entry[keylen] = sep;
    ft_strcpy(new_entry + keylen + 1, value);
    return (new_entry);
}
