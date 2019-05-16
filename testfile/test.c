/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:17:03 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/16 14:30:00 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

typedef struct	s_opp
{
	char	**name;
} 				t_opp;

char	*ft_read_main(char **av);

int main(void)
{
	int i;
	int j;
	char *result;

	t_opp g_ncase[] =
	{
		{ft_strsplit("fillit 1", ' ')},
		{ft_strsplit("run 1", ' ')},
		{ft_strsplit("fillit test_basic1.txt", ' ')},
		{ft_strsplit("fillit test_basic2.txt", ' ')},
		{ft_strsplit("fillit test_basic3.txt", ' ')},
		{ft_strsplit("fillit test_basic4.txt", ' ')},
		{ft_strsplit("fillit test_basic5.txt", ' ')},
		{ft_strsplit("fillit test_basic6.txt", ' ')},
		{ft_strsplit("fillit test_basic7.txt", ' ')},
		{ft_strsplit("fillit test_basic8.txt", ' ')},
		{ft_strsplit("fillit test_fail1.txt", ' ')},
		{ft_strsplit("fillit test_fail2.txt", ' ')},
		{ft_strsplit("fillit test_fail3.txt", ' ')},
		{ft_strsplit("fillit test_fail4.txt", ' ')},
		{ft_strsplit("fillit test_fail5.txt", ' ')},
		{ft_strsplit("fillit test_fail6.txt", ' ')},
		{ft_strsplit("fillit test_fail7.txt", ' ')},
		{ft_strsplit("fillit test_fail8.txt", ' ')},
		{ft_strsplit("fillit test_multi1.txt", ' ')}
	};

	i = -1;
	while (++i < 19)
	{
		result = ft_read_main(g_ncase[i].name);
		printf("%s result =\n%s$\n\n", g_ncase[i].name[1], result);
		ft_strdel(&result);
	}
	return (0);
}
