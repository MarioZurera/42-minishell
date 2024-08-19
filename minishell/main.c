/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 00:41:11 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/19 23:05:54 by aflorido         ###   ########.fr       */
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
	init_proc_info(&ms);
	print_banner();
	while (42)
	{
		char	*prompt = "$>"; //get_prompt(&ms); // segfaults
		ms.line = readline(prompt);
		if (ms.line == NULL)
			break ;
	}
	return (0);
}
