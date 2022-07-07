/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizsurmeli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:14:58 by denizsurmeli      #+#    #+#             */
/*   Updated: 2022/06/22 17:14:58 by denizsurmeli     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *n)
{
	t_list	*back;

	if (*lst != NULL)
	{
		back = ft_lstlast(*lst);
		back->next = n;
		return ;
	}
	*lst = n;
}
