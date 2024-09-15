/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 01:54:14 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/19 18:21:43 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "colors.h"

# include "banner.h"

// *** Constants *** //

# ifndef OK
#  define OK "\033[32mOK\033[0m"
# endif

# ifndef KO
#  define KO "\033[31mKO\033[0m"
# endif

// *** Typedefs & Enums *** //

typedef struct s_prompt		t_prompt;
typedef struct s_token		t_token;
typedef struct s_command	t_command;
typedef struct s_expr		t_expr;
typedef struct s_minishell	t_ms;

typedef enum e_token_type
{
	TT_STR, // ???
	TT_RED, // Why so cryptic?
}	t_token_type;

typedef enum e_red_type
{
	RED_IN,		//	<	(input)
	RED_OUT,	//	>	(output)
	RED_APP,	//	>>	(append)
	RED_HDOC,	//	<<	(here document)
	RED_HSTR,	//	<<< (here string)
}	t_red_type;

typedef enum e_expr_type
{
	EXPR_COMMAND,	// echo "123" > "out.txt"
	EXPR_END,		// ;
	EXPR_AND,		// &&
	EXPR_OR,		// ||
}	t_expr_type;

// *** Structures *** //

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

struct s_prompt
{
	char	*user;
	char	*host;
	char	*pwd;
	char	*home;
	char	*last_exit;
};

struct s_token
{
	t_token_type	type;
	char			*value;
};

struct s_command
{
	char			**argv;
	char			*cmd_name; // ft_strcmp(argv[0], cmd_name); -> true
	int				fd_in;
	int				fd_out;
};

struct s_expr
{
	t_expr_type		type;
	t_command		*command;
	t_expr			*next;
};

struct s_minishell
{
	char		*name;
	t_prompt	prompt;
	char		*line;
	char		***internals;
	int			last_exit_code;
};

#endif /* TYPES_H */