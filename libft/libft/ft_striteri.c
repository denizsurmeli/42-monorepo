/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizsurmeli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:35:05 by denizsurmeli      #+#    #+#             */
/*   Updated: 2022/06/22 17:15:07 by denizsurmeli     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int i, char *c))
{
	size_t	i;

	if (s == NULL || *s == 0 || f == NULL)
		return ;
	i = 0;
	while (s[i] != 0)
	{
		f(i, s + i);
		i++;
	}
}
