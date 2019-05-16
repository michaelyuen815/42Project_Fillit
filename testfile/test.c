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
		//{ft_strsplit("fillit 1", ' ')},
		//{ft_strsplit("run 1", ' ')},
		{ft_strsplit("fillit test_basic1.txt", ' ')},
		{ft_strsplit("fillit test_basic2.txt", ' ')},
		{ft_strsplit("fillit test_multi1.txt", ' ')}
	};

	i = -1;
	while (++i < 3)
	{
		result = ft_read_main(g_ncase[i].name);
		j = -1;
		while (result[++j])
			printf("result %d= %c\n", j, result[j]);
		ft_strdel(&result);
	}
	return (0);
}
