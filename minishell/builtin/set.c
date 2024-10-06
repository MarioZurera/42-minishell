#include "minishell.h"

int	_set(t_ms *ms)
{
	char	***setp;

	setp = ms->internals;
	if (!setp)
		return (1);
	while (setp)
	{
		printf("%s", (*setp)[0]);
		printf("=");
		printf("%s\n", (*setp)[1]);
		++setp;
	}
	return (0);
}

int	set(const char **argv, t_ms *ms)
{
	if (argv == NULL || argv[0] == NULL || argv[1] == NULL || argv[2] == NULL || argv[3] != NULL)
		return (_set(ms));
	if (argv[1][0] == '\0' || argv[2][0] == '\0')
		return (_set(ms));
	return (!set_internal(argv[0], argv[1], ms));
}
