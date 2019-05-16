/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:10:50 by lzhansha          #+#    #+#             */
/*   Updated: 2019/05/16 16:54:18 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_check_sides(char *str, int i)
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

int ft_check_char(char *str)
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

int ft_check_main(char *src)
{
	int i;
	int count;
	char *box;
	int j;

	j = 0;
	i = 0;
	count = 0;
	if (!src)
		return (0);
	while (src[i] && count < 26)
	{
		box = ft_strsub(src, i, 20);
		count++;
		if (ft_check_char(box) == 0)
			ft_putstr("valid\n");
		else
		{
			ft_putstr("invalid\n");
			return (-1);
		}
		i += 21;
	}
	return (1);
}
