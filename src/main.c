/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 23:17:30 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/04 01:41:02 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	print_tokens(const t_token *tokens) {
    for (int i = 0; tokens[i].op != END; i++) {
        printf("Token %d: ", i);
        if (tokens[i].op == WORD) {
            printf("Type: WORD, ");
        } else if (tokens[i].op == OPERATOR) {
            printf("Type: OPERATOR, ");
        }
        printf("Value: %s\n", tokens[i].value);
    }
}

int	main(int argc, char **argv, char **envp)
{
	char	prompt[1024];
	string	line;
	t_token	*tokens;

	(void) argc;
	(void) argv;
	(void) envp;
	bzero(prompt, 1024);
	getcwd(prompt, 1024);
	ft_strlcat(prompt, " > ", 1024);
	line = get_next_line(prompt);
	tokens = tokenize(line);
	print_tokens(tokens);
	cd("/proc/self/../../home/../home/maniel73/.");
	//cd("../../../..");
	getcwd(prompt, 1024);
	printf("%s\n", prompt);
	free(line);
	return (0);
}