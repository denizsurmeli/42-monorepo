/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizsurmeli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:14:59 by denizsurmeli      #+#    #+#             */
/*   Updated: 2022/06/22 17:14:59 by denizsurmeli     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*t;

	if (lst == NULL)
		return (NULL);
	t = lst;
	while (t->next != NULL)
	{
		t = t->next;
	}
	return (t);
}
