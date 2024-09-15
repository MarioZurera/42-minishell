/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 01:54:14 by aflorido          #+#    #+#             */
/*   Updated: 2024/09/15 19:05:16 by aflorido         ###   ########.fr       */
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
typedef struct s_expr		t_expr;
typedef struct s_minishell	t_ms;

/**
 * Token types:
 * 	TT_DEFAULT:				default value, not valid token
 * 	TT_AMPERSAND:			& (bg process)
 * 	TT_DOUBLE_AMPERSAND:	&&
 * 	TT_PIPE:				|
 * 	TT_DOUBLE_PIPE:			||
 * 	TT_LPARENS:				(
 * 	TT_RPARENS:				)
 *  TT_SEMICOLON:			;
 *  TT_SQUOTED:				single-quoted string
 *  TT_DQUOTED:				double-quoted string
 *  TT_REV_QUOTED:			reverse-quoted string
 * 	TT_REDIR_OUT:			>
 * 	TT_REDIR_APPEND:		>>
 * 	TT_REDIR_IN:			<
 * 	TT_REDIR_HDOC:			<<
 *  TT_STRING:				string
 */
typedef enum e_token_type
{
	TT_DEFAULT,
	TT_AMPERSAND,
	TT_DOUBLE_AMPERSAND,
	TT_PIPE,
	TT_DOUBLE_PIPE,
	TT_PARENTHESIS,
	TT_SEMICOLON,
	TT_SQUOTED,
	TT_DQUOTED,
	TT_REDIR_OUT,
	TT_REDIR_APPEND,
	TT_REDIR_IN,
	TT_REDIR_HDOC,
	TT_STRING,
}	t_token_type;


typedef enum e_expr_type
{
	EXPR_COMMAND,	// echo "123" > "out.txt"
	EXPR_END,		// ;
	EXPR_AND,		// &&
	EXPR_OR,		// ||
}	t_expr_type;

// *** Structures *** //

struct s_prompt
{
	char	*user;
	char	*host;
	char	*pwd;
	char	*home;
	int		last_exit;
};

/**
 * Variable value is NULL unless type is TT_STRING.
 */
struct s_token
{
	t_token_type	type;
	char			*value;
	t_token			*next;
};

/**
 * If type is EXPR_END, EXPR_AND, EXPR_OR:
 * Access to variables other than next is undefined behavior.
 */
struct s_expr
{
	t_expr_type		type;	// EXPR_COMMAND, EXPR_END, EXPR_AND, EXPR_OR
	char			**argv;
	char			*cmd_name; // ft_strcmp(argv[0], cmd_name); -> true
	int				fd_in;
	int				fd_out;
	t_expr			*next;
};

struct s_minishell
{
	char		***internals;
	int			last_exit_code;
};

/* Responsabilidades del parser */
// (RECIBIR) Lista de tokens
// interpretar variables
// wildcard
// setear in out archivos > < ?
// unir comandos y argumentos ?
// eliminar pipes
// (RETORNAR) Lista de expresiones

#endif /* TYPES_H */