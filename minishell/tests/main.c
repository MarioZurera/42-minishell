/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 00:41:11 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/04 18:10:58 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void print_header(char *header);

int	main(void)
{
	bool	exit_status;

	exit_status = 0;

	print_header("PARSE");
	bool test_dequoted_success = test_suite_dequoted();
	printf("\ttest_dequoted: %s\n", (test_dequoted_success ? OK : KO));
	exit_status |= !test_dequoted_success;

	return (exit_status);
}

static void print_header(char *header)
{
	printf("\n\t"BOLD"*** TESTING: %s ***"RESET"\n", header);
}
