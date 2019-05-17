/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:17:03 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/16 15:56:03 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

typedef struct	s_opp
{
	char	**name;
} 				t_opp;

int main(void)
{
	int i;
	int j;
	char *result;
	t_list *t_tet;
	t_list *t_tmp;

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
	while (++i < 11)
	{
		result = ft_read_main(g_ncase[i].name);
		t_tet = NULL;
		if (result)
			t_tet = ft_check_main(result);
		t_tmp = t_tet;
		printf("Case %s\n", g_ncase[i].name[1]);
		if (!t_tet)
		{
			printf("fail\n");
		}
		while (t_tmp)
		{
			j = -1;
			printf("result = %c\n", t_tmp->ch);
			while (++j < 4)
				printf("shape[%d] = %d\n\n", j, t_tmp->shape[j]);
			t_tmp = t_tmp->next;
		}
		ft_strdel(&result);
		ft_lstdel(&t_tet,&ft_bzero);
	}
	return (0);
}
