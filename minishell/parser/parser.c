#include "minishell.h"

/* Responsabilidades del parser */
// (RECIBIR) Lista de tokens
// interpretar variables
// wildcard
// setear in out archivos > < ?
// unir comandos y argumentos ?
// eliminar pipes
// (RETORNAR) Lista de expresiones
t_expr	*parser(t_token *tokens, t_ms *ms)
{
	t_expr *expr;

	expr = NULL;
	interpret_variables(tokens, ms);
	// wildcard(tokens, ms); //TODO: no tengo idea de como hacer esto
	// set_in_out(tokens, ms); //TODO: hmmm
	join_commands(tokens);
	// remove_pipes(tokens); //TODO: no recuerdo que es esto
	//TODO: en que momento se crea una expresion? :V
}
