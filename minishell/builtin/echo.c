/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:48:03 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/19 18:40:43 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo(const char **argv)
{
	int	add_new_line;

	if (argv == NULL || *argv == NULL)
	{
		printf("\n");
		return (0);
	}
	add_new_line = 1;
	if (ft_strcmp(*argv, "-n") == 0)
	{
		++argv;
		add_new_line = 0;
	}
	if (*argv != NULL)
		printf("%s", *(argv++));
	while (*argv)
	{
		printf(" ");
		printf("%s", *argv);
		++argv;
	}
	if (add_new_line)
		printf("\n");
	return (0);
}