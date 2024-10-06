#include "minishell.h"

/**
 * Adds a token to the back of the token linked list.
 */
void	add_token(t_token **token, t_token *new_token)
{
	t_token	*last;

	if (!*token)
	{
		*token = new_token;
		return ;
	}
	last = *token;
	while (last->next)
		last = last->next;
	last->next = new_token;
}
