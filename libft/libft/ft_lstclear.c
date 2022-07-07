/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizsurmeli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:14:58 by denizsurmeli      #+#    #+#             */
/*   Updated: 2022/06/22 17:14:58 by denizsurmeli     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*h;
	t_list	*track;

	h = *lst;
	while (h != NULL)
	{
		track = h->next;
		ft_lstdelone(h, del);
		h = track;
	}
	*lst = NULL;
}
