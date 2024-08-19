/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 00:41:11 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/19 19:23:19 by aflorido         ###   ########.fr       */
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
	printf("tty rows: %d\n", tty_rows());
	printf("tty cols: %d\n", tty_cols());
	while (42)
	{
		char	*prompt = get_prompt(&ms);
		ms.line = readline(prompt);
		if (ms.line == NULL)
			break ;
	}
	free_env();
	return (0);
}
