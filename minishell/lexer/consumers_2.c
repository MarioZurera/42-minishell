#include "minishell.h"

void	consume_single_quote(char **line, t_token **token)
{
	t_token	*new_token;

	new_token = ft_xmalloc(sizeof(t_token));
	new_token->type = TT_LEFT_SQUOTE;
	++(*line);
	add_token(token, new_token);
}

void	consume_double_quote(char **line, t_token **token)
{
	t_token	*new_token;

	new_token = ft_xmalloc(sizeof(t_token));
	new_token->type = TT_LEFT_DQUOTE;
	++(*line);
	add_token(token, new_token);
}

void	consume_reverse_quote(char **line, t_token **token)
{
	t_token	*new_token;

	new_token = ft_xmalloc(sizeof(t_token));
	new_token->type = TT_LEFT_REV_QUOTE;
	++(*line);
	add_token(token, new_token);
}
