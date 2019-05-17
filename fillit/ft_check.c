/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:10:50 by lzhansha          #+#    #+#             */
/*   Updated: 2019/05/17 13:36:54 by lzhansha         ###   ########.fr       */
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

int		ft_check_char(char *str, int **shape)
{
	int i;
	int block_count;
	int tot;
	int j;

	tot = 0;
	i = 0;
	j = 0;
	block_count = 0;
	while (str[i] && i < 20)
	{
		if (!(str[i] == '.' || str[i] == '#' ||
					(i % 5 == 4 && str[i] == '\n')))
			return (-1);
		if (str[i] == '#')
		{
			++block_count;
			tot += ft_check_sides(str, i);
			*shape[j++] = i;
		}
		i++;
	}
	if (!(tot == 6 || tot == 8) || block_count > 4 || !str)
		return (-1);
	return (0);
}

t_list	*ft_check_main(char *src)
{
	char	c;
	t_list	*curr;
	t_list	*list;

	c = 'A';
	list = ft_lstnew(NULL, c);
	curr = list;
	while (*src) 
	{
		if (ft_check_char(src, &(curr->shape)) != 0)
		{
			ft_lstdel(list, &ft_bzero)
			return (NULL);
		}
		if (src[20])
			curr->next = ft_lstnew(NULL, ++c);
		curr = curr->next;
		src = src + (src[20] == '\n' ? 21 : 20);
	}
	return (list);
}
