/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:10:50 by lzhansha          #+#    #+#             */
/*   Updated: 2019/05/17 20:49:04 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** function used in ft_solve for finding corresponding position for jth pt (shj)
** with 1st pt of Tetris (shj) in solving square with size (size)
*/

int		ft_check_solve_coor(int sh0, int shj, size_t size)
{
	return (shj / 5 * (size + 1) - sh0 / 5 * (size + 1)
	+ shj % 5 - sh0 % 5);
}

/*
** function of returnning no of # (total) is connecting current #
*/

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

/*
** function of saving current tetris coordination into current node (*shape)
** return 0 if passed all validation checking
** Otherwise, return -1
** validation checking includes:
** 1. character only consist ., #, \n
** 2. \n must be only placed after every 4 characters
** 3. no of # (bloack_count) must be equal to 4
** 4. total connection btw #s (tol) must be equal to 6 or 8 (all # linked tgt)
*/

int		ft_check_char(char *str, int **shape)
{
	int i;
	int block_count;
	int tot;

	tot = 0;
	i = 0;
	block_count = 0;
	while (str[i] && i < 20)
	{
		if (!(str[i] == '.' || str[i] == '#' ||
					(i % 5 == 4 && str[i] == '\n')))
			return (-1);
		if (str[i] == '#')
		{
			tot += ft_check_sides(str, i);
			if (block_count++ < 4)
				(*shape)[block_count - 1] = i;
		}
		i++;
	}
	if (!(tot == 6 || tot == 8) || block_count > 4 || !str)
		return (-1);
	return (0);
}

/*
** function of converting tetris string (*src) into linked list (*list)
** return NULL if src is NULL or total char is not correct
**		total tetris must be btw 1 and 26 and
**		total characters must be 20 + (n - 1) x 21 (where n is no. of tetris)
** for each node, it saves:
**	1. char to be printed for correspoding tetris (c)
**	2. # coordination for correspoding tetris w ft_check_char(shape)
** if valiation checking during ft_check_char fails, it delete whole *list
** and return NULL immediately
** Otherwise, return *list
*/

t_list	*ft_check_main(char *src)
{
	char	c;
	t_list	*curr;
	t_list	*list;

	c = 'A';
	list = ft_lstnew(NULL, c);
	curr = list;
	if (!src)
		return (NULL);
	if (ft_strlen(src) % 21 != 20 || ft_strlen(src) >= 26 * 21)
		return (NULL);
	while (*src)
	{
		if (ft_check_char(src, &(curr->shape)) != 0 || \
		!(src[20] == '\n' || !src[20]))
		{
			ft_lstdel(&list, &ft_bzero);
			return (NULL);
		}
		if (src[20])
			curr->next = ft_lstnew(NULL, ++c);
		curr = curr->next;
		src = src + (src[20] == '\n' ? 21 : 20);
	}
	return (list);
}
