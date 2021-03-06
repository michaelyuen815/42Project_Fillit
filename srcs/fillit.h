/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 12:09:43 by lzhansha          #+#    #+#             */
/*   Updated: 2019/05/17 20:48:58 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <fcntl.h>

# define BUFF_SIZE 1
# define STR_WRONGAC "usage: fillit input_file\n"

char	*ft_read_main(char **av);
t_list	*ft_check_main(char *src);
char	*ft_solve_main(t_list *t_tetris);
int		ft_check_solve_coor(int sh0, int shj, size_t size);

#endif
