#include "minishell.h"

/* Eliminar TT_Space */
// Quitar espacios -> parse_spaces(tokens);

/* String Quotes y Dquotes */
// interpretar variables
// wildcard
// Unir strings (quitar spaces restantes entre Strings), entonces:
//	FASE 0: Dquote -> String -> Space -> String
// 	FASE 1: Dquote+String -> Space -> String
// 	FASE 2: String(Dquote+String) -> String

/* Commands */
// Vamos a convertir strings juntos en commands

/* FD in out */
// setear in out archivos > , <
// eliminar parentesis
// Setear pipes
// Convertir comandos en expresiones

t_expr	*parser(t_token *tokens, t_ms *ms)
{
	parse_spaces(tokens);
	interpret_variables(tokens, ms);
	// wildcard(tokens, ms); //TODO: no tengo idea de como hacer esto
	// set_in_out(tokens, ms); //TODO: hmmm
	//join_commands(tokens);
	// remove_pipes(tokens); //TODO: no recuerdo que es esto
	//TODO: en que momento se crea una expresion? :V
}
