/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 23:17:30 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/04 00:31:50 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	prompt[1024];
	string	line;

	(void) argc;
	(void) argv;
	(void) envp;
	bzero(prompt, 1024);
	getcwd(prompt, 1024);
	ft_strlcat(prompt, " > ", 1024);
	line = get_next_line(prompt);
	free(line);
	return (0);
}