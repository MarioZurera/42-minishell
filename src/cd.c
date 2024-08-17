/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:48:03 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/16 14:23:40 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static char	*concat_element(char *pwd, const char *element)
{
	char	*new_pwd;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(pwd);
	if (strncmp(element, ".", len) == 0)
		return (pwd);
	if (strncmp(element, "..", len) == 0 && len > 1)
	{
		new_pwd = ft_strrchr(pwd, '/');
		new_pwd[1] = '\0';
		if (new_pwd != pwd)
			new_pwd[0] = '\0';
		return (pwd);
	}
	new_pwd = malloc(sizeof(char) * (len + ft_strlen(element) + 2));
	if (new_pwd == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		new_pwd[i] = pwd[i];
	if (new_pwd[i - 1] != '/')
		new_pwd[i++] = '/';
	j = 0;
	while ((unsigned long) j < ft_strlen(element))
		new_pwd[i++] = element[j++];
	new_pwd[i] = '\0';
	free(pwd);
	return (new_pwd);
}

static char	*concat_path(char *pwd, char *param)
{
	int	i;
	int j;
	
	if (param[0] == '/')
	{
		pwd[1] = '\0';
		param++;
	}
	i = 0;
	j = 0;
	while (param[i])
	{
		if (param[i] == '/' && i != j)
		{
			param[i] = '\0';
			pwd = concat_element(pwd, param + j);
			j = i + 1;
		}
		i++;
	}
	if (i != j)
		pwd = concat_element(pwd, param + j);
	return (pwd);
}

static int	change_path(char *pwd, char *new_pwd)
{
	int	res;

	if (new_pwd == NULL)
	{
		free(pwd);
		return (1);
	}
	res = chdir(new_pwd);
	if (res == 0)
	{
		setenv("OLDPWD", pwd, 1);
		setenv("PWD", new_pwd, 1);
	}
	free(pwd);
	free(new_pwd);
	return (res < 0);
}

static int change_to_home(char *pwd)
{
	char	*home;

	home = getenv("HOME");
	if (home == NULL)
		return (1);
	return (change_path(pwd, ft_strdup(home)));
}

static int change_to_oldpwd(char *pwd)
{
	char	*oldpwd;

	oldpwd = getenv("HOME");
	if (oldpwd == NULL)
		return (1);
	return (change_path(pwd, ft_strdup(oldpwd)));
}

int	cd(char	*new_route)
{
	char	*pwd;
	char	*new_pwd;
	char	*new_route_copy;

	pwd = NULL;
	pwd = getcwd(pwd, 0);
	if (pwd == NULL)
		return (1);
	if (new_route == NULL || new_route[0] == '\0')
		return (change_to_home(pwd));
	if (new_route[0] == '-' && new_route[1] == '\0')
		return (change_to_oldpwd(pwd));
	new_pwd = ft_strdup(pwd);
	if (new_pwd == NULL)
	{
		free(pwd);
		return (1);
	}
	new_route_copy = ft_strdup(new_route);
	new_pwd = concat_path(new_pwd, new_route_copy);
	free(new_route_copy);
	return (change_path(pwd, new_pwd));
}