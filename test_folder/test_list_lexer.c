/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_lexer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:45:16 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/03 00:09:02 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_testing.h"

void	test_list_parser(void)
{
   	ft_printf(B"================= TESTING LIST LEXER ===============\n"NC);

	
	START_TEST("Empty String:");
	{
		t_stack *result = tokenize_numbers(3, (char*[]){"", "", ""});
		assert_stack(result, NULL);
    }
	{
		t_stack *result = tokenize_numbers(3, (char*[]){"", "", " "});
		assert_stack(result, NULL);
    }
	{
		t_stack *result = tokenize_numbers(4, (char*[]){"", "     ", "           ", ""});
		assert_stack(result, NULL);
    }
	{
		t_stack *result = tokenize_numbers(4, (char*[]){"", "\t\n\r", "\v\f", " \n\n\n\t   \r\v\v\f\n"});
		assert_stack(result, NULL);
    }
	{
		t_stack *result = tokenize_numbers(10, (char*[]){"", "\r\t\n\r\v", "\f \n\n\n\t\r", "\v\v\f", "\n\n\n\t\r\v", "\v\f", "", "\n\t\n\r\v\f		\n\t\n\r\v\f \n\n\n\t\r\v", "\v\f\n\t\n\r\v\f \n\n\n\t\r\v\v\f\n", "\r"});
		assert_stack(result, NULL);
    }
	END_TEST();


	START_TEST("Valid Simple:");
    {
		t_stack s = {4, (int []){1, 2, 3, 42}};
		t_stack *result = tokenize_numbers(5, (char*[]){"", "1", "2", "3", "42"});
		assert_stack(result, &s);
    }
    {
		t_stack s = {6, (int []){1, 2, 3, 4, 5, 6}};
		t_stack *result = tokenize_numbers(7, (char*[]){"", "\t1", "\t2\n", "3\r", "4", "\v5\f", "6\t"});
		assert_stack(result, &s);

    }
    {
		t_stack s = {6, (int []){10, -10, 9, -9, 10, -10}};
		t_stack *result = tokenize_numbers(7, (char*[]){"", "10",  "-10", "9", "-9", "10", "-10"});
		assert_stack(result, &s);
    }
	END_TEST();


	START_TEST("Invalid Simple:");
	{
		t_stack *result = tokenize_numbers(5, (char*[]){"", "1", "two", "3", "4"});
		assert_stack(result, NULL);
    }
	{
		t_stack *result = tokenize_numbers(6, (char*[]){"", "\t1\t", "2", "\n3", "\rfour", "\v5"});
		assert_stack(result, NULL);
    }
	{
		t_stack *result = tokenize_numbers(3, (char*[]){"", "42b42", "42"});
		assert_stack(result, NULL);
    }
	{
		t_stack *result = tokenize_numbers(3, (char*[]){"", "42b", "42"});
		assert_stack(result, NULL);
    }
	{
		t_stack *result = tokenize_numbers(3, (char*[]){"", "42", "b42"});
		assert_stack(result, NULL);
    }
	END_TEST();


	START_TEST("Valid Extreme:");
	{
		t_stack s = {2, (int []){INT_MAX, INT_MAX - 1}};
		t_stack *result = tokenize_numbers(3, (char *[]){"", "2147483647", "2147483646"});
		assert_stack(result, &s);
    }
	{
		t_stack s = {2, (int []){INT_MIN, INT_MIN + 1}};
		t_stack *result = tokenize_numbers(3, (char *[]){"", "-2147483648", "-2147483647"});
		assert_stack(result, &s);
    }
    {
		t_stack s = {5, (int []){INT_MAX, INT_MIN, 0, INT_MAX - 1, INT_MIN + 1}};
		t_stack *result = tokenize_numbers(6, (char *[]){"", "2147483647", "-2147483648", "0", "2147483646", "-2147483647"});
		assert_stack(result, &s);
    }
	END_TEST();


	START_TEST("Invalid Extreme:");
	{
		t_stack *result = tokenize_numbers(3, (char *[]){"", "1234567890", "09876543210"});
		assert_stack(result, NULL);
    }
    {
		t_stack *result = tokenize_numbers(3, (char *[]){"", "2147483647", "2147483648"});
		assert_stack(result, NULL);
    }
	{
		t_stack *result = tokenize_numbers(3, (char *[]){"", "-2147483648", "-2147483649"});
		assert_stack(result, NULL);
    }
	END_TEST();
	

	ft_printf(B"=================== END LIST LEXER =================\n\n"NC);
}