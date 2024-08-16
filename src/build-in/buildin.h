#ifndef BUILDIN_H
# define BUILDIN_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_minishell
{
	char	**envp;
}	t_ms;

void	cd(char **argv, t_ms ms);

#endif