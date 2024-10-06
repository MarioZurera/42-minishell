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
	if (str[i] != '\0' && ft_strchr("0123456789@*#-$?!", str[i]) != NULL)
		return (ft_substr(str, 0, 1));
	while (str[i] != '\0' && (ft_isalnum(str[i]) || str[i] == '_'))
		++i;
	if (i == 0)
		return (NULL);
	return (ft_substr(str, 0, i));
}

/**
 * @brief Changes variable names in string tokens to their values.
 * 
 * A variable is any string starting with an unescaped $,
 * within a TT_STRING or TT_DQUOTE token.
 */
void	interpret_variables(t_token *token, t_ms *ms)
{
	t_token	*curr;
	char	*variable_name;
	char	*variable_value;
	char	*new_token_value;
	int		i;

	curr = token;
	while (curr != NULL)
	{
		if (curr->type != TT_STRING && curr->type != TT_DQUOTE)
			continue ;
		i = 0;
		while (curr->value && curr->value[i] != '\0')
		{
			if (curr->value[i] == '$' && (i == 0 || curr->value[i - 1] != '\\'))
			{
				variable_name = ft_get_variable(curr->value + i + 1);
				if (variable_name != NULL)
				{
					variable_value = get_internal(variable_name, ms);
					if (variable_value == NULL)
						variable_value = "";
					new_token_value = ft_strjoin_free(ft_substr(curr->value, 0, i), variable_value, 1, 0);
					i += ft_strlen(variable_name);
					free(variable_name);
					new_token_value = ft_strjoin_free(new_token_value, curr->value + i + 1, 1, 0);
					curr->value = new_token_value;
				}
			}
			++i;
		}
		curr = curr->next;
	}
}
