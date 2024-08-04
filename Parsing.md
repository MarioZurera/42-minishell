# Parsing


### Reglas de transformación (Transformation rules)
-----------
* EXP -> PL (`&&` | `||` | `;`) PL
* EXP -> PL  
-----------
* PL -> CMD `|` CMD
* PL -> CMD
-----------
* CMD -> BIN {WS}+ RED+ (WS+ ARG+) (any number, any order)*
-----------
* RED -> (`<`, `<<`, `>`, `>>`, `>>>`) {WS}+ WORD
* ARG -> WORD
-----------
* WORD -> CMDSUB
* WORD -> VAR
* WORD -> STR
-----------
### Legend
EXP		=== Expression

PL		=== Pipeline

CMD		=== Command

BIN		=== Binary (ie: echo, cat, ls, wc, cd)

RED		=== Redirection (ie: `>cosas.txt`, `>   cosas.txt`)

ARG		=== Argument (WORD)

WORD	=== Word (CMDSUB|VAR|STR)

CMDSUB	=== Command substitution, subshell (`CMD` | $(CMD))
