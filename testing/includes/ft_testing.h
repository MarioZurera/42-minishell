/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:31:49 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 15:59:11 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TESTING
# define FT_TESTING

# include "colors.h"
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct	s_test
{
	const char	*name;
	bool			error;
	int			count;
}	t_test;


void	START_TEST(const char *test_name);

void	ASSERT(bool test_result);

void	END_TEST();


#endif /* FT_TESTING */