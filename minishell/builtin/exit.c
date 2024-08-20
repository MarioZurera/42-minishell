/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <aflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:48:03 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/19 18:40:43 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static long long	ft_atoll(const char *s)
{
   long long	num;
   int		   sign;
   int	   	i;

   i = 0;
   while (ft_isspace(s[i]))
      ++i;
   sign = 1;
   if (s[i] == '+' || s[i] == '-')
      if (s[i++] == '-')
         sign = -1;
   num = 0;
   while (ft_isdigit(s[i]))
      {
      num *= 10;
      num += s[i] - '0';
      ++i;
   }
   return (num * sign);
}

static int is_long(const char *s)
{
   long long	num;

   if (!ft_isnumber(s))
      return (0);
   num = ft_atoll(s);
   return (num <= LONG_MAX && num >= LONG_MIN);
}

void	ms_exit(t_ms *ms, char *param)
{
   // free_ms(ms);
   if (!param)
      exit(ms->last_exit_code);
   if (!is_long(param))
      exit(2);
   exit(ft_atol(param));
}
