/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:51:41 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/06 05:13:07 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Reads characters from file descriptor into the buffer until newline
** is found or the end of file is reached. Joins the buffer content
** to the static leftover string from previous calls.
**
** @param  fd         The file descriptor to read from.
** @param  left_str   The static string containing leftovers from previous reads.
** @return            The updated string containing read characters including
**                    the newline character if it was found.
*/
char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr_line(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin_line(left_str, buff);
	}
	free(buff);
	return (left_str);
}

/*
** Retrieves the next line from the file descriptor specified.
** A line is defined as a sequence of characters followed by a '\n' or EOF.
**
** @param  fd   The file descriptor to read from.
** @return      A string containing the next line from the file descriptor.
*/
char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}
