/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 09:29:38 by aflorido          #+#    #+#             */
/*   Updated: 2024/08/18 18:01:31 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Replaces the HOME directory found at the beginning of the PWD with a ~
 * If it is found, the old pwd is freed
 */
static char	*update_pwd(char *pwd, char *home)
{
	char	*new_pwd;

	if (!pwd || !home)
		return (pwd);
	if (ft_strncmp(pwd, home, ft_strlen(home)) == 0)
	{
		new_pwd = ft_strjoin("~", pwd + ft_strlen(home));
		if (new_pwd == NULL)
			return (pwd);
		free(pwd);
		return (new_pwd);
	}
	return (pwd);
}

/**
 * Read env values to update the prompt variables
 */
static void	read_env_to_prompt(t_ms *ms)
{
	ft_free_all(5, ms->prompt.user, ms->prompt.host, ms->prompt.pwd,
		ms->prompt.home, ms->prompt.last_exit);
	ms->prompt.user = ft_strdup(getenv("USER"));
	ms->prompt.host = ft_strdup(getenv("HOSTNAME"));
	if (ms->prompt.host == NULL)
		ms->prompt.host = ft_strdup("minishell");
	ms->prompt.pwd = ft_strdup(getenv("PWD"));
	ms->prompt.home = ft_strdup(getenv("HOME"));
	ms->prompt.last_exit = ft_strdup(getenv("?"));
	if (ms->prompt.last_exit == NULL)
		ms->prompt.last_exit = ft_strdup("0");
}

/**
 * The prompt will have the form:
 * 'USER@HOST:PWD$ '
 * Where PWD substitutes the HOME directory with a ~
 * 
 * ### Colors:
 * - `USER@HOST` in green
 * - `:` in default color
 * - `PWD` in blue
 * - `$` in green if the last command was successful, in red if not
 * 
 * The length of the prompt is calculated taking into account the lengths of
 * the strings, the separator characters, the colors(7 to set, 6 to reset)
 */
char	*get_prompt(t_ms *ms)
{
	int		prompt_len;
	char	*prompt;

	read_env_to_prompt(ms);
	ms->prompt.pwd = update_pwd(ms->prompt.pwd, ms->prompt.home);
	prompt_len = ft_strlen(ms->prompt.user) + ft_strlen(ms->prompt.host)
		+ ft_strlen(ms->prompt.pwd) + 4 + 13 + 13 + 13;
	prompt = ft_calloc(prompt_len + 1, sizeof(char));
	if (prompt == NULL)
		return (NULL);
	build_prompt(prompt, &(ms->prompt));
	return (prompt);
}
