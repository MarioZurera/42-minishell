/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:21:58 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/19 23:07:07 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * init_proc_info will initialize information
 * read from /proc/self/status and from /etc/passwd
 * 
 * Specifically the fields:
 * - pid
 * - ppid
 * - uid
 * - gid
 * - euid
 * - egid
 * - username
 * - groupname
 * 
 */
void    init_proc_info(t_ms *ms)
{
    (void)ms;
    // TODO: implement this function
}
