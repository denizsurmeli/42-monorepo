/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizsurmeli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:35:03 by denizsurmeli      #+#    #+#             */
/*   Updated: 2022/06/22 17:15:04 by denizsurmeli     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	len_s1;
	size_t	i;

	len_s1 = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0')
	{
		s1[len_s1 + i] = s2[i];
		i++;
	}
	s1[len_s1 + i] = '\0';
	return (s1);
}
