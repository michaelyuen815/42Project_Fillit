/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:10:50 by lzhansha          #+#    #+#             */
/*   Updated: 2019/05/17 12:30:57 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_sides(char *str, int i)
{
	int total;

	total = 0;
	if (str[i - 1] == '#' && i > 0)
		total++;
	if (str[i + 1] == '#' && i + 1 < 20)
		total++;
	if (str[i - 5] == '#' && i >= 5)
		total++;
	if (str[i + 5] == '#' && i + 5 < 20)
		total++;
	return (total);
}

int		ft_check_char(char *str)
{
	int i;
	int block_count;
	int tot;

	tot = 0;
	i = 0;
	block_count = 0;
	if (!str)
		return (-1);
	while (str[i] && i < 20)
	{
		if (!(str[i] == '.' || str[i] == '#' ||
					(i % 5 == 4 && str[i] == '\n')))
			return (-1);
		if (str[i] == '#')
		{
			++block_count;
			tot += ft_check_sides(str, i);
		}
		i++;
	}
	if (!(tot == 6 || tot == 8) || block_count > 4)
		return (-1);
	return (0);
}

char	*ft_check_array(char *box, int count)
{
	int		i;
	char	*tet;
	int		j;

	i = 0;
	j = 0;
	tet = ft_strnew(16);
	while (box[i])
	{
		if (box[i] != '\n')
		{
			if (box[i] == '.')
				tet[j % 16] = box[i];
			else
				tet[j % 16] = 'A' + count;
			j++;
		}
		i++;
	}
	return (tet);
}

t_list		ft_check_main(char *src)
{
	int		i;
	char	*box;
	t_list	*tetris;

	i = 0;
	tetris = NULL;
	if (!src)
		return (tetris);
	while (src[i * 20 + (i - 1)] && i < 26)
	{
		box = ft_strsub(src, i * 21, 20);
		if (ft_check_char(box) != 0)
		{
			free(box);
			return (-1);
		}
		else
			tetris = ft_check_create(box);
		i++;
	}
	return (tetris);
}
