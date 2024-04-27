/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 03:02:39 by myakoven          #+#    #+#             */
/*   Updated: 2024/04/24 16:56:47 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_clearfree(buffer, line));
	line = ft_strjoinbuff(line, buffer);
	if (!line)
		return (ft_clearfree(buffer, line));
	line = ft_read(fd, line, buffer);
	if (!line)
		return (NULL);
	line = ft_takeline(line, buffer);
	if (!ft_strlen(line))
		return (ft_clearfree(buffer, line));
	return (line);
}

/* take substr and clean up buffer to be without prev line*/
char	*ft_takeline(char *line, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*newline;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	newline = ft_substr(line, 0, i);
	free(line);
	j = 0;
	while (buffer[j] != '\n' && buffer[j])
		j++;
	if (buffer[j] == '\n')
		j++;
	buffer = ft_memmove(buffer, (buffer + j), (BUFFER_SIZE - j));
	j = (BUFFER_SIZE - j);
	while (j < BUFFER_SIZE)
		buffer[j++] = 0;
	return (newline);
}

char	*ft_strjoinbuff(char *s1, char const *buff)
{
	size_t	len_s1;
	size_t	lenbuff;
	size_t	i;
	size_t	j;
	char	*string;

	len_s1 = ft_strlen(s1);
	lenbuff = ft_strlen(buff);
	i = 0;
	j = 0;
	string = malloc(sizeof(char) * (len_s1 + BUFFER_SIZE) + 1);
	if (!(string))
		return (NULL);
	while (i < (len_s1))
	{
		string[i] = s1[i];
		i++;
	}
	while (i < (len_s1 + lenbuff))
	{
		string[i++] = buff[j++];
	}
	string[i] = 0;
	return (string);
}

char	*ft_clearfree(char *buffer, char *line)
{
	ft_bzero(buffer, BUFFER_SIZE);
	if (!line)
		return (NULL);
	free(line);
	return (NULL);
}

char	*ft_read(int fd, char *line, char *buffer)
{
	int		i;
	int		bytes_read;
	char	*newline;

	bytes_read = 1;
	if (ft_strchr(buffer, '\n'))
		bytes_read = 0;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < BUFFER_SIZE && bytes_read >= 0)
		{
			i = bytes_read;
			while (i < BUFFER_SIZE)
				buffer[i++] = 0;
		}
		newline = ft_strjoinbuff(line, buffer);
		if (!newline || bytes_read == -1)
			return (ft_clearfree(buffer, line));
		free(line);
		line = newline;
		if (ft_strchr(line, '\n'))
			break ;
	}
	return (line);
}
/*
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
NOTE: 
*/
