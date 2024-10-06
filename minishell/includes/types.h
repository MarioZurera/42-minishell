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
 * 	TT_LEFT_PARENTHESIS:	(
 * 	TT_RIGHT_PARENTHESIS:	)
 *  TT_SEMICOLON:			;
 *  TT_SQUOTE:				single-quote (')
 *  TT_DQUOTE:				double-quote (")
 *  TT_REV_QUOTED:			reverse-quote (`)
 * 	TT_REDIR_OUT:			>
 * 	TT_REDIR_APPEND:		>>
 * 	TT_REDIR_IN:			<
 * 	TT_REDIR_HDOC:			<<
 *  TT_STRING:				string
 */
typedef enum e_token_type
{
	TT_DEFAULT,
	TT_SPACE,
	TT_AMPERSAND,
	TT_DOUBLE_AMPERSAND,
	TT_PIPE,
	TT_DOUBLE_PIPE,
	TT_LEFT_PARENTHESIS,
	TT_RIGHT_PARENTHESIS,
	TT_SEMICOLON,
	// Quotes
	TT_SQUOTE,
	TT_DQUOTE,
	TT_BQUOTE,
	// Redirections
	TT_REDIR_OUT,
	TT_REDIR_APPEND,
	TT_REDIR_IN,
	TT_REDIR_HDOC,
	// String
	TT_STRING,
	// Command
	TT_COMMAND,
}	t_token_type;

typedef enum e_expr_type
{
	EXPR_COMMAND,	// echo "123" > "out.txt"
	EXPR_END,		// ;
	EXPR_AND,		// &&
	EXPR_OR,		// ||
}	t_expr_type;

// *** Structures *** //

/**
 * List structure. Unused in the project but kept for utils functions to use.
 */
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
	int		last_exit;
};

/**
 * Variable value is NULL unless type is
 * TT_STRING, TT_SQUOTE, TT_DQUOTE, TT_REV_QUOTE.
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
	union {
		t_expr		*expr;
		t_token		*token;
	} next;
};

struct s_minishell
{
	char		***internals;
	int			last_exit_code;
};

#endif /* TYPES_H */