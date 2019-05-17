/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 12:12:33 by lzhansha          #+#    #+#             */
/*   Updated: 2019/05/16 17:02:10 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int ac, char **av)
{
	char *str_src;

	if (ac != 2)
		ft_putstr_fd(STR_WRONGAC, 2);
	else if (ac == 2) 
	{
		str_src = ft_read_main(av[1]);
		if (ft_check_main(str_src) != 1)
		{
			ft_putstr_fd("error\n", 2);
			return (0);
		}
	}
	return (0);
}
