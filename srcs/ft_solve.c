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

/*
** function of finding the smallest possible square size based on no. of #
** return round up square root value of no. of #s (int_tetris)
*/

int		ft_solve_initsize(int int_tetris)
{
	int ret;

	ret = 2;
	while (ret * ret < int_tetris)
		ret++;
	return (ret);
}

/*
** function of undo current tetris pts (shape) filling and change used flag to 0
** if current correspoding index (index) is outside the square (line 46) or
** at the \n (line 47), end process immediately
*/

int		ft_solve_unfillone(char *result, t_list *t_cur, size_t size, size_t i)
{
	size_t j;
	size_t index;

	t_cur->used = 0;
	j = -1;
	while (++j < 4)
	{
		index = i + ft_check_solve_coor(t_cur->shape[0], t_cur->shape[j], size);
		if (index >= size * (size + 1)
		|| index % (size + 1) == size)
			return (0);
		if (!result[index] || result[index] == t_cur->ch)
			result[index] = '.';
	}
	return (0);
}

/*
** function of trying to fill all current tetris pt (shape) to char (ch)
** Step 1: finding correspoding index (index) for shape[j] w ft_check_solve_coor
** Step 2: if current index (index) is out of square (line 75),
**			\n pt (line 76) or fill with other char (line 78)
**			unfill the current tetris with ft_solve_unfillone and return 0
**			Otherwise, update index to char (ch) (line 79)
** Step 3: repeat Step 1-2 for all pts (j, from 0 - 3)
** Step 4: if all pts are filled, change used flag to 1 and return 1 (line 83)
*/

int		ft_solve_fillone(char *result, t_list *t_cur, size_t size, size_t i)
{
	size_t	j;
	size_t	index;

	j = -1;
	while (++j < 4)
	{
		index = i + ft_check_solve_coor(t_cur->shape[0], t_cur->shape[j], size);
		if (index >= size * (size + 1)
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

/*
** recursive function of filling all tetris into a square with size (size)
** Step 1: return 1 if t_cur is NULL (all tetris are tried)
** Step 2: if ith pt at \n pt, fill \n (line 111, 112)
**			if current tetris is used (used = 1) and ith pt is unfilled,
**			fill "." (line 113, 114)
** Step 3: if current tetris is not used (used = 0) and ith pt is unfilled,
**			try fill current tetris with ft_solve_fillone (line 115, 116)
** Step 4: if step 3 return 1, run recursion with next tetris (t_cur->next)
**			if not all remaining tetris are able to be filled, undo
**			filling with function ft_solve_unfillone (line 117, 118)
** Step 5: repeat step 2 - 4 for all pts in square
** Step 6: return 1 if current tetris is filled. Otherwise, return 0
*/

int		ft_solve_fillall(char *result, t_list *t_cur, size_t size)
{
	size_t	i;

	if (!t_cur)
		return (1);
	i = -1;
	while (++i < size * (size + 1))
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

/*
** function of finding small square of filling all tetris
** Step 1: define smallest possible square with ft_solve_initsize (line 140)
** Step 2: create result string (result) with size (line 141)
** Step 3: check whether all tetris is able to fill in current size sqaure
**			(line 142)
** Step 4: if step 3 fails, increase size by 1 and repeat step 2-4
**			until it works and return return result (line 142 - 148)
*/

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
