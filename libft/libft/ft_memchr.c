/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizsurmeli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:30:41 by denizsurmeli      #+#    #+#             */
/*   Updated: 2022/06/22 17:15:01 by denizsurmeli     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	void	*loc;

	loc = NULL;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (i < n)
	{
		if (*((char *)(s + i)) == c)
		{
			loc = (void *)(s + i);
			break ;
		}
		i++;
	}
	return (loc);
}
