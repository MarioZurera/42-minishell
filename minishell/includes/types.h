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

typedef struct s_list		t_list;
typedef struct s_token		t_token;
typedef struct s_prompt		t_prompt;
typedef struct s_minishell	t_ms;

typedef enum e_token_type
{
	TT_STR,
	TT_RED,
}	t_token_type;

typedef enum e_red_type
{
	RED_IN,		//	<	(input)
	RED_OUT,	//	>	(output)
	RED_APP,	//	>>	(append)
	RED_HDOC,	//	<<	(here document)
	RED_HSTR,	//	<<< (here string)
}	t_red_type;

// *** Structures *** //

struct s_list
{
	void			*content;
	struct s_list	*next;
};

struct s_token
{
	t_token_type	type;
	char			*value;
};

struct s_prompt
{
	char	*user;
	char	*host;
	char	*pwd;
	char	*home;
	char	*last_exit;
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