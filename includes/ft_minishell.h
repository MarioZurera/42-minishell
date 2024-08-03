/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 23:15:00 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/04 01:40:44 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL
# define FT_MINISHELL

# include "../libft/libft.h"
# include "../libft/colors.h"
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct	s_token
{
	enum { WORD, OPERATOR, END } op;
	string					value;
}	t_token;

typedef struct	s_minishell
{

}	s_ms;

string	get_next_line(const char *prompt);

t_token	*tokenize(string line);

#endif /* FT_MINISHELL */