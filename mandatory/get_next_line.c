/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:29:39 by asaadane          #+#    #+#             */
/*   Updated: 2023/04/07 22:32:04 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// This function reads a line from a file descriptor and appends it to a string
// until a newline character is found or the end of the file is reached.

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
// It uses a buffer of size BUFFER_SIZE to read the line.
		if (readed_bytes == -1)
		{
			free(buffer);
			free(hold);
			return (NULL);
// If any errors occur during the read operation,
// the function frees the allocated memory and returns NULL.
		}
		buffer[readed_bytes] = '\0';
		hold = ft_strjoin(hold, buffer);
	}
	free(buffer);
	return (hold);
// Finally, it frees the buffer and returns the updated string hold.
}

// This function takes a line in hold as input
// and returns a whole line with "\n".

char	*ft_hold_line(char *hold)
{
	char	*str;
	int		i;

	i = 0;
	if (!hold || !hold[i])
		return (NULL);	// If the input string is empty or null, the function returns NULL.
	while (hold[i] && hold[i] != '\n')
		i++;
	i += (hold[i] == '\n');
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (hold[i] && hold[i] != '\n')
	{
		str[i] = hold[i];	// It also modifies the value of the input string's pointer (hold)
		i++;				// to point to the next character after "\n".
	}
	if (hold[i] == '\n')
	{
		str[i] = hold[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*This function extracts a substring from the hold string that comes after the line string.
It first checks if the line pointer is null, and then allocates memory for a new string str.
It copies the characters from hold starting from the index after the last character of line and up to the end of the string into str.
Finally, it frees the memory allocated to hold and returns str.
*/
char	*ft_sub_hold(char *hold, char *line)
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
	static char	*hold;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	hold = ft_read_and_hold(fd, hold);
	if (!hold)
		return (NULL);
	line = ft_hold_line(hold);
	hold = ft_sub_hold(hold, line);
	return (line);
}

// void ok(void)
// {
// 	 system("leaks a.out");
// }

// int main(void)
// {
// 	int i;

// 	i = 0;
// 	atexit(ok);
// 	int fd = open("ff", O_RDONLY);
// 	char *str;
// 	// str = get_next_line(fd);
// 	while ((str = get_next_line(fd)) > 0)
// 	{
// 		printf("%s\n", str);
// 		free(str);
// 	}
// }