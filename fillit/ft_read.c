/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:08:13 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/16 14:11:48 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "fcntl.h"

#define BUFF_SIZE 1
#define STR_WGOPEN ": No such file or directory\n"
#define STR_WGREAD ": Error during reading\n"

static void	ft_print_erropen(char *str_pgm, char *str_file)
{
	ft_putstr_fd("./", 2);
	ft_putstr_fd(str_pgm, 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd(str_file, 2);
	ft_putstr_fd(STR_WGOPEN, 2);
}

static char	*ft_print_errread(char *str_pgm, char *str_file)
{
	ft_putstr_fd("./", 2);
	ft_putstr_fd(str_pgm, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str_file, 2);
	ft_putstr_fd(STR_WGREAD, 2);
	return (NULL);
}

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
	if (fd > 2)
	{
		if (!(str_buff = ft_strnew(BUFF_SIZE)))
			return (ft_print_errread(av[0], av[1]));
		while ((rd = read(fd, str_buff, BUFF_SIZE)) > 0)
			str_src = ft_read_combine(&str_src, str_buff, rd);
		free(str_buff);
		close(fd);
		if (fd < 0)
			return (ft_print_errread(av[0], av[1]));
	}
	else
		ft_print_erropen(av[0], av[1]);
	return (str_src);
}
