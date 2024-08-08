/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 00:41:11 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/08 14:35:43 by aflorido         ###   ########.fr       */
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
int	main(int argc, char **argv, char **envp)
{
	t_ms	ms;

	(void)argc;
	(void)argv;
	ms.env = init_env(envp);
	print_banner();
	print_env(ms.env);
	while (1)
	{
		ms.line = readline(get_prompt(&ms));
		printf("line: %s\n", ms.line);
	}
	free_env(ms.env);
	return (0);
}
