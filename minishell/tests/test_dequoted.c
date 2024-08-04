/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dequoted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:50:30 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/04 18:00:58 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static bool test_dequoted(char *to_dequote, char *expected, int line)
{
	char	*dequoted;

	dequoted = dequote(to_dequote);
	if (strcmp(dequoted, expected) != 0)
	{
		if (TEST_VERBOSE)
		{
			printf("Error on file: "CYAN"%s"RESET"\n", __FILE__);
			printf("Error on line "CYAN"%d"RESET"\n", line);
			printf(RED"Expected: %s, got: %s\n"RESET, expected, dequoted);
		}
		free(dequoted);
		return (false);
	}
	if (TEST_VERBOSE)
		printf(GREEN"Success: "RESET"[%s] -> [%s]\n", to_dequote, dequoted);
	free(dequoted);
	return (true);
}

bool test_suite_dequoted(void)
{
	bool test1 = test_dequoted("echo", "echo", __LINE__);
	bool test2 = test_dequoted("e\"c\"h\"\"o", "echo", __LINE__);
	bool test3 = test_dequoted("\"a'b'c\"", "a'b'c", __LINE__);
	bool test4 = test_dequoted("'a\"b\"c'", "a\"b\"c", __LINE__);
	bool test5 = test_dequoted("echo \"hello world\"", "echo hello world", __LINE__);
	return (test1 && test2 && test3 && test4 && test5);
}
