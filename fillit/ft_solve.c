/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 11:03:29 by lzhansha          #+#    #+#             */
/*   Updated: 2019/05/17 20:53:27 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_solve_initsize(int int_tetris)
{
	int ret;

	ret = 2;
	while (ret * ret < int_tetris)
		ret++;
	return (ret);
}

int		ft_solve_unfillone(char *result, t_list *t_cur, size_t size, size_t i)
{
	size_t j;
	size_t index;

	t_cur->used = 0;
	j = -1;
	while (++j < 4)
	{
		index = i + ft_check_solve_coor(t_cur->shape[0], t_cur->shape[j], size);
		if (index < 0 || index > size * (size + 1)
		|| index % (size + 1) == size)
			return (0);
		if (!result[index] || result[index] == t_cur->ch)
			result[index] = '.';
	}
	return (0);
}

int		ft_solve_fillone(char *result, t_list *t_cur, size_t size, size_t i)
{
	size_t	j;
	size_t	index;

	j = -1;
	while (++j < 4)
	{
		index = i + ft_check_solve_coor(t_cur->shape[0], t_cur->shape[j], size);
		if (index < 0 || index > size * (size + 1)
		|| index % (size + 1) == size)
			return (ft_solve_unfillone(result, t_cur, size, i));
		if (!result[index] || result[index] == '.')
			result[index] = t_cur->ch;
		else
			return (ft_solve_unfillone(result, t_cur, size, i));
	}
	t_cur->used = 1;
	return (1);
}

int		ft_solve_fillall(char *result, t_list *t_cur, size_t size)
{
	size_t	i;

	if (!t_cur)
		return (1);
	i = -1;
	while (++i <= size * (size + 1))
	{
		if (i % (size + 1) == size)
			result[i] = '\n';
		if (t_cur->used && !result[i])
			result[i] = '.';
		if (!t_cur->used && (!result[i] || result[i] == '.'))
			if (ft_solve_fillone(result, t_cur, size, i))
				if (!ft_solve_fillall(result, t_cur->next, size))
					ft_solve_unfillone(result, t_cur, size, i);
	}
	if (t_cur->used)
		return (1);
	return (0);
}

char	*ft_solve_main(t_list *t_tetris)
{
	size_t	size;
	char	*result;

	size = ft_solve_initsize(4 * ft_lstlen(t_tetris));
	result = ft_strnew(size * (size + 1));
	while (!ft_solve_fillall(result, t_tetris, size))
	{
		ft_strdel(&result);
		size++;
		result = ft_strnew(size * (size + 1));
	}
	return (result);
}
