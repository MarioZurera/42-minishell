#include "minishell.h"

/**
 * Joins adjacent string (TT_STRING) into a single one, since they are
 * part of the same command.
 */
void	join_commands(t_token **token)
{
	t_token	*current;
	t_token	*next;
	char	*new_value;

	current = *token;
	while (current)
	{
		if (current->type == TT_STRING)
		{
			next = current->next;
			while (next && next->type == TT_STRING)
			{
				new_value = ft_strjoin(current->value, next->value);
				free(current->value);
				current->value = new_value;
				current->next = next->next;
				free(next->value);
				free(next);
			}
		}
		current = current->next;
	}
}
