/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 12:12:33 by lzhansha          #+#    #+#             */
/*   Updated: 2019/05/16 12:30:45 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

 ft_read_file(int fd)
{

}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("usage: ");
		return ();
	}
	else if (ac == 2) 
	{
		ft_read_file(open(av[1], ))
	}
	return (0);
}
