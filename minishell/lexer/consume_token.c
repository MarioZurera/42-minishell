#include "minishell.h"

/**
 * Consumes a token from the input line.
 * 
 * The token is added to the token linked list.
 * The line pointer is updated to the next char after the token.
 */
void	consume_token(char **line, t_token **token)
{
	if (**line == '&')
		consume_amp(line, token);
	else if (**line == '|')
		consume_pipe(line, token);
	else if (**line == '(')
		consume_lparen(line, token);
	else if (**line == ')')
		consume_rparen(line, token);
	else if (**line == ';')
		consume_semicolon(line, token);
	else if (**line == '\'')
		consume_single_quote(line, token);
	else if (**line == '\"')
		consume_double_quote(line, token);
	else if (**line == '`')
		consume_reverse_quote(line, token);
	else if (**line == '>')
		consume_gt(line, token);
	else if (**line == '<')
		consume_lt(line, token);
	else
		consume_string(line, token);
}
