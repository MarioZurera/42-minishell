/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 01:54:14 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/05 19:38:07 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "colors.h"

// *** Constants ***

# ifndef OK
#  define OK "\033[32mOK\033[0m"
# endif

# ifndef KO
#  define KO "\033[31mKO\033[0m"
# endif

// *** Types ***

typedef char	*string;

// *** Structures ***

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_btree
{
	void			*item;
	struct s_btree	*left;
	struct s_btree	*right;
}	t_btree;

#endif /* TYPES_H */