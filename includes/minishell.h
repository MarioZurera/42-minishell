/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 00:41:35 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/04 02:01:32 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// *** Structures ***
# include "types.h"

// *** Prototypes ***
# include "functions.h"

// *** Libraries for allowed functions ***

# include <readline/readline.h>
// readline, rl_clear_history, rl_on_new_line,
// rl_replace_line, rl_redisplay

# include <readline/history.h>
// add_history

# include <stdio.h>
// printf, perror

# include <stdlib.h>
// malloc, free, exit, getenv

# include <unistd.h>
// write, access, read, close, fork, getcwd, chdir,
// unlink, execve, dup, dup2, pipe, isatty, ttyname,
// ttyslot

# include <fcntl.h>
// open

# include <sys/wait.h>
// wait, waitpid, wait3, wait4

# include <signal.h>
// signal, sigaction, sigemptyset, sigaddset, kill

# include <sys/stat.h>
// stat, lstat, fstat

# include <dirent.h>
// opendir, readdir, closedir

# include <string.h>
// strerror

# include <sys/ioctl.h>
// ioctl

# include <termios.h>
// tcsetattr, tcgetattr

# include <term.h>
// tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs

// *** Libraries for constant macros ***

# include <stdbool.h>
# include <errno.h>
# include <limits.h>

// *** All allowed functions ***
/*
	readline, rl_clear_history, rl_on_new_line,
	rl_replace_line, rl_redisplay, add_history,
	printf, malloc, free, write, access, open, read,
	close, fork, wait, waitpid, wait3, wait4, signal,
	sigaction, sigemptyset, sigaddset, kill, exit,
	getcwd, chdir, stat, lstat, fstat, unlink, execve,
	dup, dup2, pipe, opendir, readdir, closedir,
	strerror, perror, isatty, ttyname, ttyslot, ioctl,
	getenv, tcsetattr, tcgetattr, tgetent, tgetflag,
	tgetnum, tgetstr, tgoto, tputs
*/

#endif /* MINISHELL_H */