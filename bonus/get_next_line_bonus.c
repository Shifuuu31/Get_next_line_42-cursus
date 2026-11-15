/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:29:26 by asaadane          #+#    #+#             */
/*   Updated: 2023/04/07 20:10:10 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_and_hold(int fd, char *hold)
{
	char	*buffer;
	int		readed_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	readed_bytes = 1;
	while (!ft_strchr(hold, '\n') && readed_bytes != 0)
	{
		readed_bytes = read(fd, buffer, BUFFER_SIZE);
		if (readed_bytes == -1)
		{
			free(buffer);
			free(hold);
			return (NULL);
		}
		buffer[readed_bytes] = '\0';
		hold = ft_strjoin(hold, buffer);
	}
	free(buffer);
	return (hold);
}

char	*ft_hold_line(char *hold)
{
	char	*str;
	int		i;

	if (!hold || !hold[0])
		return (NULL);
	i = 0;
	while (hold[i] && hold[i] != '\n')
		i++;
	i += (hold[i] == '\n');
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (hold[i] && hold[i] != '\n')
	{
		str[i] = hold[i];
		i++;
	}
	if (hold[i] == '\n')
	{
		str[i] = hold[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_hold(char *hold, char *line)
{
	char	*str;
	int		i;
	int		j;

	i = ft_strlen(line);
	j = 0;
	if (!line)
		return (free(hold), NULL);
	if (!hold[i] || hold[i] == '\0')
		return (free(hold), NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(hold) - i + 1));
	if (!str)
		return (NULL);
	while (hold[i])
		str[j++] = hold[i++];
	str[j] = '\0';
	free(hold);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*hold[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (0);
	hold[fd] = ft_read_and_hold(fd, hold[fd]);
	if (!hold[fd])
		return (NULL);
	line = ft_hold_line(hold[fd]);
	hold[fd] = ft_hold(hold[fd], line);
	return (line);
}
