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
	char	*line;

	(void)argc;
	(void)argv;
	init(&ms);
	while (42)
	{
		char	*prompt = "$>"; //get_prompt(&ms); // segfaults
		line = readline(prompt);
		if (line == NULL)
			break ;
		free(line);
	}
	return (0);
}

void	init(t_ms *ms)
{
	ft_bzero(ms, sizeof(t_ms));
	//TODO: disable printing control characters (like ^C) to the terminal
	init_env();
	init_proc_info(ms);
	init_internal(ms);
	print_banner();
}
