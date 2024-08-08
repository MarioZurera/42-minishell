/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:55:14 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/08 14:31:17 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define RESET		"\033[0m"
# define BOLD		"\033[1m"
# define DIM		"\033[2m"
# define ITALIC		"\033[3m"
# define UNDERLINE	"\033[4m"
# define BLINK		"\033[5m"
# define INVERTED	"\033[7m"
# define HIDDEN		"\033[8m"

# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

/**
 * Readline colors are surrounded by \001 and \002 to ensure
 * that the cursor is placed correctly after the prompt
 */
# define RL_RESET	"\001\033[0m\002"
# define RL_BLACK	"\001\033[30m\002"
# define RL_RED		"\001\033[31m\002"
# define RL_GREEN	"\001\033[32m\002"
# define RL_YELLOW	"\001\033[33m\002"
# define RL_BLUE	"\001\033[34m\002"
# define RL_MAGENTA	"\001\033[35m\002"
# define RL_CYAN	"\001\033[36m\002"
# define RL_WHITE	"\001\033[37m\002"

#endif /* COLORS_H */