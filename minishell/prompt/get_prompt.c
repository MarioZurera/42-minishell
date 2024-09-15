/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 09:29:38 by aflorido          #+#    #+#             */
/*   Updated: 2024/09/15 19:16:47 by aflorido         ###   ########.fr       */
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
static void	read_env_to_prompt(int last_exit, t_prompt *prompt)
{
	prompt->user = getenv("USER");
	if (prompt->user == NULL)
		prompt->user = "guest";
	prompt->host = getenv("HOSTNAME");
	if (prompt->host == NULL)
		prompt->host = "minishell";
	prompt->pwd = getcwd(NULL, 0);
	prompt->home = getenv("HOME");
	if (prompt->home == NULL)
		prompt->home = "/home/guest";
	prompt->last_exit = last_exit;
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
 * the strings, the separator characters, the colors (7 to set, 6 to reset)
 */
char	*get_prompt(t_ms *ms)
{
	t_prompt	prompt;
	int		prompt_len;
	char	*str_prompt;

	read_env_to_prompt(ms->last_exit_code, &prompt);
	prompt.pwd = update_pwd(prompt.pwd, prompt.home);
	prompt_len = ft_strlen(prompt.user) + ft_strlen(prompt.host)
		+ ft_strlen(prompt.pwd) + 4 + 13 + 13 + 13;
	str_prompt = ft_calloc(prompt_len + 1, sizeof(char));
	if (str_prompt == NULL)
		return (free(prompt.pwd), NULL);
	build_prompt(str_prompt, &prompt);
	return (free(prompt.pwd), str_prompt);
}
