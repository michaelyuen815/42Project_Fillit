/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 12:12:33 by lzhansha          #+#    #+#             */
/*   Updated: 2019/05/21 15:25:52 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	char	*str_src;
	t_list	*t_tetris;
	char	*result;

	if (ac != 2)
		ft_putstr(STR_WRONGAC);
	else
	{
		str_src = ft_read_main(av);
		if (!(t_tetris = ft_check_main(str_src)))
			ft_putstr("error\n");
		else
		{
			result = ft_solve_main(t_tetris);
			ft_putstr(result);
			ft_strdel(&result);
		}
		if (!str_src)
			ft_strdel(&str_src);
		if (!t_tetris)
			ft_lstdel(&t_tetris, &ft_bzero);
	}
	return (0);
}
