/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:27:02 by mskeleto          #+#    #+#             */
/*   Updated: 2020/12/31 19:53:12 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_zero(char *buffer, int i)
{
	if (i == BUFFER_SIZE)
		return (1);
	while (i < (BUFFER_SIZE + 1))
	{
		buffer[i] = '\0';
		i++;
	}
	return (1);
}

void	ft_free(char ***remain)
{
	if (**remain != NULL)
	{
		free(**remain);
		**remain = NULL;
	}
}

int		ft_result(int status)
{
	int			result;

	if (status <= 0)
		result = status;
	else
		result = 1;
	return (result);
}

int		ft_check_remain(char ***line, char **remain)
{
	char		*tmp;
	int			i;

	i = 0;
	**line = ft_strjoin(**line, *remain);
	if (ft_nsymbol(*remain) == 0)
	{
		tmp = (char*)ft_calloc(ft_strlen(*remain) + 1, sizeof(char));
		while ((*remain)[i] != '\0')
		{
			tmp[i] = (*remain)[i];
			i++;
		}
		ft_free(&remain);
		*remain = ft_strdup(tmp);
		free(tmp);
		return (0);
	}
	ft_free(&remain);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int			status;
	char		*buffer;
	static char	*remain;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || !(*line = ft_strdup("\0")))
		return (-1);
	if (remain)
		if (ft_check_remain(&line, &remain) == 0)
			return (1);
	if (!(buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char))))
		return (-1);
	status = 1;
	while ((status > 0) && ft_nsymbol(buffer))
	{
		if ((status = read(fd, buffer, BUFFER_SIZE)) > 0)
			ft_zero(buffer, status);
		if (status > 0)
			*line = ft_strjoin(*line, buffer);
	}
	if (status > 0)
		remain = ft_strdup(buffer);
	free(buffer);
	buffer = NULL;
	return (ft_result(status));
}
