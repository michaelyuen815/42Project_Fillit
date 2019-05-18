/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 11:03:29 by lzhansha          #+#    #+#             */
/*   Updated: 2019/05/17 11:07:40 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    ft_solve_unfillone(char *reusult, t_list *tmp, size_t size, size_t i)
{

}

int     ft_solve_fillone(char *result, t_list *t_tmp, size_t size, size_t i)    //check whether the node can fill in position i and fill it if possible
{

}

int     ft_solve_fillall(char *result, t_list *t_cur, size_t size)
{
    size_t  i;

    if (!t_cur)
        return (1);
    i = 0;
    while (i <= size * (size + 1))
    {
        if (t_cur->used && !result[i])
            result[i] = '.';
        if (!t_cur->used && (!result[i] || result[i] == '.')
        {
            if (ft_solve_fillone(result, t_cur, size, i))
                t_cur->used = 1;
                if (!ft_solve_fillall(result, t_cur->next, size))
                    t_cur->used = 0; 
                    ft_solve_unfillone();
                    result[i] = '.';
        }
        i++;
    }
    if (t_cur->used)
        return (1);
    return (0);
}

char	*ft_solve_main(t_list *t_tetris, int num)
{
	size_t size;
    char    *result;

    size = roundup(sqrt(4 * no. of node));
    result = ft_strnew(size * (size + 1));

    while (!ft_solve_fillall(result, t_tetris, size))
    {
        ft_strdel(result);
        size++;
        result = ft_strnew(size * (size + 1));
    }
    return (result);
}
