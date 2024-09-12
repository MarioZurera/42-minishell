/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:22:42 by mzurera-          #+#    #+#             */
/*   Updated: 2024/09/12 14:12:05 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	execute_builtin(const t_command *command, t_ms *ms)
{
	if (ft_strncmp(command->cmd_name, "cd", 2) == 0)
		cd(command->argv[1]);
	else if (ft_strncmp(command->cmd_name, "echo", 4) == 0)
		echo(command->argv);
	else if (ft_strncmp(command->cmd_name, "env", 3) == 0)
		env();
	else if (ft_strncmp(command->cmd_name, "exit", 4) == 0)
		ms_exit(command->argv[1], ms);
	else if (ft_strncmp(command->cmd_name, "export", 6) == 0)
		export(command->argv[1], ms);
	else if (ft_strncmp(command->cmd_name, "pwd", 3) == 0)
		pwd();
	else if (ft_strncmp(command->cmd_name, "set", 3) == 0)
		set(command->argv, ms);
	else if (ft_strncmp(command->cmd_name, "unset", 5) == 0)
		unset(command->argv[1], ms);
	else
		return (0);
	return (1);
}

static char	*try_fullname(const char *cmd_name, char **paths, int index)
{
	char	*possible_fullname;

	possible_fullname = ft_strjoin(paths[index], cmd_name);
	if (possible_fullname == NULL)
		return (NULL);
	if (access(possible_fullname, F_OK) == -1)
	{
		free(possible_fullname);
		return (NULL);
	}
	return (possible_fullname);
}

static int	find_command(char **cmd_name)
{
	char	*fullname;
	char	**paths;
	int		i;

	paths = ft_split(getenv("PATH"), ':');
	if (paths == NULL)
		return (0);
	fullname = NULL;
	i = 0;
	while (paths[i] != NULL && fullname == NULL)
		fullname = try_fullname(*cmd_name, paths, i++);
	free(*cmd_name);
	*cmd_name = fullname;
	return (fullname != NULL);
}

static void execute_command(t_expr *expression, t_ms *ms)
{
	int			pid;
	t_command	*command;

	command = expression->command;
	if (command == NULL)
	{
		printf(RED"Execute command NULL?"RESET);
		return ;
	}
	if (execute_builtin(command, ms))
		return ;
	if (!find_command(&command->cmd_name))
		return ;
	pid = fork();
	if (pid < 0)
	{
		printf(RED"FATAL ERROR while forking"RESET);
		return ;
	}
	if (pid > 0)
		return ;
	dup2(command->fd_in, STDIN_FILENO);
	dup2(command->fd_out, STDOUT_FILENO);
	free_expression(expression);
	execve(command->cmd_name, command->argv, environ);
}

// Caution: Ensure heap contains only t_expr to prevent leaks.

void	execute(t_expr *expression, t_ms *ms)
{
	if (expression == NULL)
		return ;
	while (expression->type == EXPR_COMMAND)
	{
		execute_command(expression, ms);
		expression = expression->next;
	}
	execute(expression->next, ms);
}
