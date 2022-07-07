/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizsurmeli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:35:05 by denizsurmeli      #+#    #+#             */
/*   Updated: 2022/06/22 17:15:07 by denizsurmeli     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	size_t	i;

	i = 0;
	if ((s1 == NULL) || (s2 == NULL))
		return (s1 == s2);
	if (ft_strlen((char *)s1) != ft_strlen((char *)s2))
		return (0);
	while (s1[i] != 0 && s2[i] != 0)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
