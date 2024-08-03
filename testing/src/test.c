/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:32:54 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 21:03:49 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_testing.h"

static t_test	test;

void	START_TEST(const char *test_name)
{
    test.name = test_name;
	test.error = false;
	test.count = 0;
	printf(B"%-21s"NC, test_name);
	fflush(stdout);
}

void	ASSERT(bool test_result)
{
	if (test.error)
		return ;
	test.count++;
	if (test_result == false)
	{
		fprintf(stderr, R"\tError in test %d\n"NC, test.count);
		fflush(stderr);
		test.error = true;
	}
	else
	{
		printf(G"."NC);
		fflush(stdout);
	}
}

void	END_TEST()
{
	if (test.error == true || test.name == NULL)
		return ;
	printf(G"\tAll %d test passed!\n"NC, test.count);
	fflush(stdout);
	test.name = NULL;
}