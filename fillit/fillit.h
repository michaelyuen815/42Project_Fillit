/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 12:09:43 by lzhansha          #+#    #+#             */
/*   Updated: 2019/05/17 09:42:59 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <fcntl.h>

# define BUFF_SIZE 1
# define STR_WGOPEN ": No such file or directory\n"
# define STR_WGREAD ": Error during reading\n"
# define STR_WRONGAC "usage: ./fillit target_file"

extern char **g_tetris;

char		*ft_read_combine(char **str_src, char *str_buff, int rd);
char		*ft_read_main(char **av);
char		*ft_read_main(char **av);
int			ft_check_main(char *src);
int			ft_check_char(char *str);
int			ft_check_sides(char *str, int i);

#endif
