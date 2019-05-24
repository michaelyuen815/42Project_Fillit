/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:08:13 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/21 15:40:44 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_read_combine(char **str_src, char *str_buff, int rd)
{
	char *tmp_buff;
	char *tmp_src;

	tmp_buff = ft_strsub(str_buff, 0, rd);
	tmp_src = ft_strjoin(*str_src, tmp_buff);
	ft_strdel(&tmp_buff);
	ft_strdel(str_src);
	*str_src = tmp_src;
	return (tmp_src);
}

char		*ft_read_main(char **av)
{
	int		fd;
	int		rd;
	char	*str_buff;
	char	*str_src;

	fd = open(av[1], O_RDONLY);
	str_src = NULL;
	if (fd >= 0)
	{
		if (!(str_buff = ft_strnew(BUFF_SIZE)))
			return (str_src);
		while ((rd = read(fd, str_buff, BUFF_SIZE)) > 0)
			str_src = ft_read_combine(&str_src, str_buff, rd);
		free(str_buff);
		close(fd);
		if (fd < 0)
			return (str_src);
	}
	return (str_src);
}
