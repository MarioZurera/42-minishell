#include "minishell.h"

static char	*ft_strjoin_free(char *s1, char *s2, int free_s1, int free_s2)
{
	char	*new_str;

	new_str = ft_strjoin(s1, s2);
	if (free_s1)
		free(s1);
	if (free_s2)
		free(s2);
	return (new_str);
}

/**
 * Extracts the variable name from a string, stopping at the first invalid char.
 */
static char *ft_get_variable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && (ft_isalnum(str[i]) || str[i] == '_'))
		++i;
	if (i == 0)
		return (NULL);
	return (ft_substr(str, 0, i));
}

/**
 * Changes variables in string tokens to their values.
 * A variable is any string starting with a $, unless it is escaped
 * or in single quotes (previous token is a TT_LEFT_SQUOTE).
 */
void	interpret_variables(t_token *token, t_ms *ms)
{
	t_token	*prev;
	t_token	*current;
	char	*variable_name;
	char	*variable_value;
	char	*token_value;
	char	*new_token_value;
	int		i;

	prev = NULL;
	current = token;
	while (current)
	{
		if (current->type == TT_STRING)
		{
			token_value = current->value;
			i = 0;
			while (token_value[i] != '\0')
			{
				if (token_value[i] == '$' && (i == 0 || token_value[i - 1] != '\\'))
				{
					variable_name = ft_get_variable(token_value + i + 1);
					if (variable_name != NULL)
					{
						variable_value = get_internal(variable_name, ms);
						if (variable_value == NULL)
							variable_value = "";
						new_token_value = ft_strjoin_free(ft_substr(token_value, 0, i), variable_value, 1, 0);
						i += ft_strlen(variable_name);
						free(variable_name);
						new_token_value = ft_strjoin_free(new_token_value, token_value + i + 1, 1, 0);
						current->value = new_token_value;
					}
				}
				++i;
			}
		}
		prev = current;
		current = current->next;
	}
}
