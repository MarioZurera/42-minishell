/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:30:31 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 21:40:36 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_testing.h"
#include "push_swap.h"

t_stack	*create_stack(unsigned int size, int *nums)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));

	stack->size = size;
	stack->list = nums;

	return (stack);
}

static bool	cmp_stack(t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	i;

	if (stack_a == stack_b)
		return (true);
	if (stack_a == NULL || stack_b == NULL)
		return (false);
	if (stack_a->size != stack_b->size)
		return (false);
	i = 0;
	while (i < stack_a->size)
	{
		if (stack_a->list[i] != stack_b->list[i])
			return (false);
		i++;
	}
	return (true);
}

void	assert_stack(t_stack *stack_a, t_stack *stack_b)
{
	ASSERT(cmp_stack(stack_a, stack_b));
	if (stack_a != NULL)
		free(stack_a->list);
	free(stack_a);
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
    test_string_parser();
    test_list_parser();
    return (0);    
}