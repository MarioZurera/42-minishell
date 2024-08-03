#include "ft_testing.h"

int sum(int x, int y)
{
    return (x + y);
}

int sub(int x, int y)
{
    return (x - y);
}


void	sum_simple(void)
{
    START_TEST("Sum Simple:");
    ASSERT(sum(0, 0) == 0);
    ASSERT(sum(1, 0) == 1);
    ASSERT(sum(0, 1) == 1);
    END_TEST();
}

void	sum_positive(void)
{
    START_TEST("Sum Positive:");
    ASSERT(sum(13, 48) == 61);
    ASSERT(sum(73, 82) == 155);
    ASSERT(sum(1512, 48327) == 49839);
    END_TEST();
}

void	sub_simple(void)
{
    START_TEST("Sub Simple:");
    ASSERT(sub(0, 0) == 0);
    ASSERT(sub(1, 0) == 1);
    ASSERT(sub(0, 1) == -1);
    END_TEST();
}

void	sub_positive(void)
{
    START_TEST("Sub Positive:");
    ASSERT(sub(13, 48) == -35);
    ASSERT(sub(73, 82) == -9);
    ASSERT(sub(48327, 1512) == 46815);
    END_TEST();
}

int main(void)
{
	sum_simple();
	sum_positive();
	// sum_one_negative();
	// sum_two_negative();
	// sub_conmutation();
	// sum_big_possitive();
	// sum_big_negative();

	sub_simple();
	sub_positive();
	// sub_one_negative();
	// sub_two_negative();
	// sub_opposition_in_conmutation();
	// sub_big_possitive();
	// sub_big_negative();
}
