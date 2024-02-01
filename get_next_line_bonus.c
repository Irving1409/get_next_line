/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ircaetan <ircaetan@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:08:48 by ircaetan          #+#    #+#             */
/*   Updated: 2024/01/31 22:57:57 by ircaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_buffer(int fd)
{
	char		*line;
	static char	*buffer[MAX_FD];
	int			result_read;

	line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	result_read = 1;
	while (result_read > 0 && !find_n(buffer[fd]))
	{
		result_read = read(fd, line, BUFFER_SIZE);
		if (result_read < 0)
		{
			free(line);
			return (NULL);
		}
		line[result_read] = '\0';
		buffer[fd] = ft_strjoin(buffer[fd], line);
	}
	free(line);
	if (!buffer[fd])
		return (NULL);
	line = gnl_first_part_of(buffer[fd]);
	buffer[fd] = gnl_second_part_of(buffer[fd]);
	return (line);
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (read_buffer(fd));
}
/*
#include <fcntl.h>
#include <stdio.h>
int main ()
{
	int fd = open("text.txt", O_RDONLY);

	char *line;

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}	
}
*/
