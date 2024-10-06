#include "minishell.h"

void	consume_gt(char **line, t_token **token)
{
	t_token	*new_token;

	new_token = ft_xmalloc(sizeof(t_token));
	new_token->type = TT_REDIR_OUT;
	++(*line);
	if (**line == '>')
	{
		new_token->type = TT_REDIR_APPEND;
		++(*line);
	}
	add_token(token, new_token);
}

void	consume_lt(char **line, t_token **token)
{
	t_token	*new_token;

	new_token = ft_xmalloc(sizeof(t_token));
	new_token->type = TT_REDIR_IN;
	++(*line);
	if (**line == '<')
	{
		new_token->type = TT_REDIR_HDOC;
		++(*line);
	}
	add_token(token, new_token);
}

/**
 * Consumes a string token from the input line.
 * 
 * This function also sets the token value to the string.
 */
void	consume_string(char **line, t_token **token)
{
	t_token	*new_token;
	char	*start;

	new_token = ft_xmalloc(sizeof(t_token));
	new_token->type = TT_STRING;
	start = *line;
	//TODO: handle quotes and escaped characters
	while (**line && !ft_isspace(**line) && !ft_strchr("<>|&;()\'\"`", **line))
		++(*line);
	new_token->value = ft_substr(start, 0, *line - start);
	add_token(token, new_token);
}
