/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:18:53 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/25 17:45:17 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_getline_strjoin(const char *s1,
	const char *s2, unsigned int extra_size)
{
	char			*str;
	unsigned int	length;
	unsigned int	dest_len;
	unsigned int	cat_len;

	length = ft_strlen(s1) + ft_strlen(s2) + extra_size;
	str = (char *) malloc(sizeof(char) * length);
	if (str == NULL)
	{
		free((char *) s1);
		return (NULL);
	}
	ft_strlcpy(str, s1, length);
	free((char *) s1);
	dest_len = ft_strlen(str);
	if (dest_len + ft_strlen(s2) < length)
		cat_len = ft_strlen(s2);
	else
		cat_len = length - dest_len - 1;
	ft_memcpy(str + dest_len, s2, cat_len);
	str[dest_len + cat_len] = '\0';
	return (str);
}

static int	contains_new_line(char *buffer, char **str, int pos)
{
	int		new_len;
	char	*temp;

	new_len = ft_strlen(*str) - pos;
	if (pos != -1)
	{
		ft_strlcpy(buffer, *str + pos + 1, new_len);
		temp = ft_substr(*str, 0, pos + 1);
		if (temp == NULL)
			return (0);
		free(*str);
		*str = temp;
	}
	(*str)[pos] = '\n';
	return (pos != -1);
}

static int	contains_null_character(char *buffer, char **str)
{
	int		pos;
	char	*temp;

	buffer[0] = '\0';
	pos = ft_strlen(*str);
	temp = ft_substr(*str, 0, pos);
	if (temp == NULL)
		return (0);
	free(*str);
	*str = temp;
	return (1);
}

static int	read_line(int fd, char *buffer, char **str)
{
	int		bytes;
	int		eof;

	eof = 0;
	if (buffer[0] == '\0')
		bytes = read(fd, buffer, BUFFER_SIZE);
	else
		bytes = ft_strlen(buffer);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		eof = (buffer[bytes - 1] != '\0');
		*str = ft_getline_strjoin(*str, buffer, eof);
		if (*str == NULL)
			return (0);
		if (ft_strchr_i(*str, '\n') >= 0)
		{
			if (!contains_new_line(buffer, str, ft_strchr_i(*str, '\n')))
				return (0);
			break ;
		}
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	return (bytes > 0 || (bytes == 0 && eof
			&& contains_null_character(buffer, str)));
}

char	*get_next_line(int fd)
{
	static char	buffer[FD_LIMIT][BUFFER_SIZE + 1];
	char		*str;
	int			control;

	if (fd < 0 || fd >= FD_LIMIT)
		return (NULL);
	str = (char *) malloc(1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	control = read_line(fd, buffer[fd], &str);
	if (!control)
	{
		buffer[fd][0] = '\0';
		free(str);
		return (NULL);
	}
	return (str);
}
