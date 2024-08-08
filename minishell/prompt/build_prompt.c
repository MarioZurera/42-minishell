/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:44:01 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/08 14:58:02 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	unsafe_concat(char *prompt, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (prompt[i] != '\0')
		i++;
	j = 0;
	while (str[j] != '\0')
	{
		prompt[i] = str[j];
		i++;
		j++;
	}
}

void	build_prompt(char *prompt, t_prompt *data)
{
	unsafe_concat(prompt, RL_GREEN);
	unsafe_concat(prompt, data->user);
	unsafe_concat(prompt, "@");
	unsafe_concat(prompt, data->host);
	unsafe_concat(prompt, RL_RESET);
	unsafe_concat(prompt, ":");
	unsafe_concat(prompt, RL_BLUE);
	unsafe_concat(prompt, data->pwd);
	unsafe_concat(prompt, RL_RESET);
	if (ft_strcmp(data->last_exit, "0") != 0)
		unsafe_concat(prompt, RL_GREEN);
	else
		unsafe_concat(prompt, RL_RED);
	unsafe_concat(prompt, "$ ");
	unsafe_concat(prompt, RL_RESET);
}
