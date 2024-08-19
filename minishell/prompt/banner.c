/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   banner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:37:16 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/19 22:11:46 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_hside(int cols, char corner)
{
	int		i;

	printf(CYAN"%c", corner);
	i = 2;
	while (i < cols)
	{
		printf("-");
		i++;
		if (i < cols)
		{
			printf("=");
			i++;
		}
	}
	printf("%c"RESET"\n", corner);
}

static void	print_banner_start(int space)
{
	int		i;

	if (space < 2)
	{
		while (space--)
			printf(" ");
		return ;
	}
	printf(CYAN"|");
	i = 1;
	while (i < space)
	{
		printf(" ");
		i++;
	}
	printf(RESET);
}

static void	print_banner_end(int space)
{
	int		i;

	if (space < 2)
	{
		while (space--)
			printf(" ");
		return ;
	}
	i = 1;
	while (i < space)
	{
		printf(" ");
		i++;
	}
	printf(CYAN"|"RESET"\n");
}

void	print_banner(void)
{
	const char	*banner[BANNER_HEI] = {
		COLOR_BANNER_0, COLOR_BANNER_1, COLOR_BANNER_2, COLOR_BANNER_3,
		COLOR_BANNER_4, COLOR_BANNER_5, COLOR_BANNER_6, COLOR_BANNER_7};
	int			cols;
	int			space;
	int			i;

	cols = tty_cols();
	if (cols < 0)
		cols = 80;
	else if (cols < BANNER_WID)
		return ;
	space = cols - BANNER_WID;
	if (space >= 4)
		print_hside(cols, '.');
	i = 0;
	while (i < BANNER_HEI)
	{
		print_banner_start((space >> 1) + (space % 2));
		printf("%s", banner[i]);
		print_banner_end(space >> 1);
		i++;
	}
	if (space >= 4)
		print_hside(cols, '\'');
}
