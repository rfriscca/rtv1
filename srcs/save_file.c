/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfriscca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 12:20:10 by rfriscca          #+#    #+#             */
/*   Updated: 2016/10/10 14:34:53 by rfriscca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_line	*save_file(int fd)
{
	int		ret;
	t_line	*file_start;
	t_line	*file;
	char	*line;
	int		i;


	i = 0;
	if ((ret = get_next_line(fd, &line)) == -1)
		error(3);
	if (ret <= 0 || (file_start = ft_new_line(line, ft_strlen(line))) == NULL)
		error(3);
	file = file_start;
	if ((ret = get_next_line(fd, &line)) == -1)
		error(3);
	while (ret > 0)
	{
		file->next = ft_new_line(line, ft_strlen(line));
		file = file->next;
		if ((ret = get_next_line(fd, &line)) == -1)
			error(3);
		++i;
	}
	free(line);
	return (file_start);
}
