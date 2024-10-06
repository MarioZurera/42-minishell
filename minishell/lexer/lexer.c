#include "minishell.h"

/**
 * Tokenizes the input line into a list of tokens.
 */
t_token	*lexer(char *line, t_ms *ms)
{
	t_token	*token;

	//TODO: dequote empty quotes + check for unbalanced quotes ?
	token = NULL;
	while (line && *line != '\0')
	{
		if (ft_isspace(*line))
			++line;
		else
			consume_token(&line, &token);
	}
	return (token);
}
