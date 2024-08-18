/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:50:47 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/18 16:25:35 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(void)
{
	int	i;

	i = 0;
	while (environ && environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
