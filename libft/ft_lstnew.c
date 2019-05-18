/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 10:56:20 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/03 11:13:57 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**linked list function of creating a new node
**with assigning value (*content) and size (content_size)
**keep content_size 0 in node if content is NULL
*/

t_list	*ft_lstnew(int const *shape, char ch)
{
	t_list *ret;

	if (!(ret = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	ret->content_size = 4 * sizeof(int);
	ret->ch = ch;
	ret->used = 0;
	if (!(ret->shape = ft_memalloc(ret->content_size)))
	{
		free(ret);
		return (NULL);
	}
	if (shape)
		ft_memcpy((void*)ret->shape, (void*)shape, ret->content_size);
	ret->next = NULL;
	return (ret);
}
