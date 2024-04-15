/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-abbo <fel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 04:59:39 by fel-abbo          #+#    #+#             */
/*   Updated: 2024/03/31 18:39:42 by fel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	stock[BUFFER_SIZE + 1];
	char		*built_line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	built_line = NULL;
	built_line = ft_strjoin(built_line, stock);
	bytes_read = 1;
	while (!ft_strchr(built_line, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, stock, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(built_line), NULL);
		stock[bytes_read] = '\0';
		built_line = ft_strjoin(built_line, stock);
		if (built_line == NULL)
			return (NULL);
	}
	if (!built_line[0])
		return (free(built_line), NULL);
	else
		extract_line(built_line, stock);
	return (built_line);
}
