#include "minishell.h"

/**
 * malloc with error handling (exit on failure)
 */
void	*ft_xmalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		perror("malloc failed");
		exit(1);
	}
	return (ptr);
}
