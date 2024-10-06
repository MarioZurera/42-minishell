#include "minishell.h"

void	consume_amp(char **line, t_token **token)
{
	t_token	*new_token;

	new_token = xmalloc(sizeof(t_token));
	new_token->type = TT_AMPERSAND;
	++(*line);
	if (**line == '&')
	{
		new_token->type = TT_DOUBLE_AMPERSAND;
		++(*line);
	}
	add_token(token, new_token);
}

void	consume_pipe(char **line, t_token **token)
{
	t_token	*new_token;

	new_token = xmalloc(sizeof(t_token));
	new_token->type = TT_PIPE;
	++(*line);
	if (**line == '|')
	{
		new_token->type = TT_DOUBLE_PIPE;
		++(*line);
	}
	add_token(token, new_token);
}

void	consume_lparen(char **line, t_token **token)
{
	t_token	*new_token;

	new_token = xmalloc(sizeof(t_token));
	new_token->type = TT_LEFT_PARENTHESIS;
	++(*line);
	add_token(token, new_token);
}

void	consume_rparen(char **line, t_token **token)
{
	t_token	*new_token;

	new_token = xmalloc(sizeof(t_token));
	new_token->type = TT_RIGHT_PARENTHESIS;
	++(*line);
	add_token(token, new_token);
}

void	consume_semicolon(char **line, t_token **token)
{
	t_token	*new_token;

	new_token = xmalloc(sizeof(t_token));
	new_token->type = TT_SEMICOLON;
	++(*line);
	add_token(token, new_token);
}
