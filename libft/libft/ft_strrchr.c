/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizsurmeli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:35:09 by denizsurmeli      #+#    #+#             */
/*   Updated: 2022/06/22 17:15:11 by denizsurmeli     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s1, char c)
{
	size_t	i;

	i = ft_strlen(s1);
	if (s1 == NULL)
		return (NULL);
	if (c == '\0')
		return ((char *)(s1 + ft_strlen(s1)));
	while (i > 0)
	{
		if (s1[i - 1] == c)
		{
			return ((char *)(s1 + (i - 1)));
		}
		i--;
	}
	return (NULL);
}
