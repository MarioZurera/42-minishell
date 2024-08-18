/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 00:41:11 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/18 16:33:05 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * main - Entry point.
 * 
 * If 1 arg is passed, start the shell.
 * If 3 args are passed and the second is "-c",
 * execute the command passed as the third argument.
 * Otherwise, print an error message.
 */
int	main(int argc, char **argv)
{
	t_ms	ms;

	(void)argc;
	(void)argv;
	ft_bzero(&ms, sizeof(t_ms));
	init_env();
	print_banner();
	//print_env();
	while (1)
	{
		char	*prompt = get_prompt(&ms);
		ms.line = readline(prompt);
	}
	free_env();
	return (0);
}
