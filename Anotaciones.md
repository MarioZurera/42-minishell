
# FIXME: Cosas por arreglar
- Todo al dia

# TODO: Cosas por hacer
### Prioridad alta
- Añadir libft al proyecto
		(se propone no añadir libft como tal, sino añadir en una carpeta aparte, por ejemplo, minishell/utils, las funciones que se necesiten. estas funciones pueden tener sus prototipos en el header functions.h)
- Añadir estructuras y typedefs necesarios a types.h
### Prioridad baja
- Mantener fichero functions.h actualizado con los prototipos de todas las funciones

# Propuestas / Cambios
- [Header] Definir constantes para todos los literales de string que se utilicen
- [Memoria] Intentar que las variables y estructuras que existan durante todo el programa esten en el stack (no malloc, no puntero)



### Here Docs
Los here_docs (cmd << EOF) expanden siempre variabes a no ser que lleven una comilla doble o simple en el delimitador, independientemente de donde las lleve. Tampoco lleva comillas al terminar el here_doc.
