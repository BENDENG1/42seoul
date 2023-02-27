/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:26:00 by gyroh             #+#    #+#             */
/*   Updated: 2022/08/18 16:19:09 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*n_value;

	if (!lst || !f)
		return (0);
	tmp = 0;
	while (lst)
	{
		n_value = ft_lstnew(f(lst -> content));
		if (!n_value)
		{
			ft_lstclear(&tmp, del);
			return (0);
		}
		ft_lstadd_back(&tmp, n_value);
		lst = lst -> next;
	}
	n_value = 0;
	return (tmp);
}
