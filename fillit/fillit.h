/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 12:09:43 by lzhansha          #+#    #+#             */
/*   Updated: 2019/05/17 12:35:39 by lzhansha         ###   ########.fr       */
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

char	*ft_read_main(char **av);
t_list	*ft_check_main(char *src);

#endif
