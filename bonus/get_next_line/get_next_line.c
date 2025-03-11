/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:24:46 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/11 14:11:02 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*extract_line(char *storage)
{
	char	*line;
	int		i;

	if (!storage || !*storage)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = ft_substr(storage, 0, i);
	return (line);
}

char	*update_storage(char *storage)
{
	char	*new_storage;
	int		i;

	if (!storage)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i] || storage[i] == '\n')
	{
		free(storage);
		return (NULL);
	}
	new_storage = ft_substr(storage, i + 1, ft_strlen(storage) - i - 1);
	free(storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = read_file(fd, storage);
	if (!storage || *storage == '\0')
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	line = extract_line(storage);
	storage = update_storage(storage);
	return (line);
}
