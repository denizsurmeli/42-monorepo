/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizsurmeli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:35:07 by denizsurmeli      #+#    #+#             */
/*   Updated: 2022/06/22 17:15:09 by denizsurmeli     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	i = 0;
	while (i < n && s2[i] != 0)
	{
		s1[s1_len + i] = s2[i];
		i++;
	}
	s1[s1_len + i] = '\0';
	return (s1);
}
