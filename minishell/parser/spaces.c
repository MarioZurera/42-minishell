#include "minishell.h"

static int is_stringish_token(t_token *token)
{
    return (token->type == TT_STRING
            || token->type == TT_SQUOTE
            || token->type == TT_DQUOTE
            || token->type == TT_BQUOTE);
}

/**
 * Removes unnecessary spaces from the token list.
 * 
 * Spaces are unnecessary when they don't separate kinds of strings
 * (like TT_STRING, TT_SQUOTE, TT_DQUOTE, TT_BQUOTE).
 */
t_token *aijvsdibsd(t_token *tokens, t_ms *ms)
{
    t_token *prev;
    t_token *curr;
    t_token *next;

    prev = tokens;
    while (prev && prev->next && prev->next->next)
    {
        curr = prev->next;
        next = curr->next;
        if (curr->type == TT_SPACE && !(is_stringish_token(prev) && is_stringish_token(next)))
        {
            prev->next = next;
            free(curr);
        }
        prev = prev->next;
    }
    return (tokens);
}
