/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizsurmeli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 23:36:55 by denizsurmeli      #+#    #+#             */
/*   Updated: 2022/06/22 17:15:01 by denizsurmeli     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dest_to_uc;
	unsigned char	*src_to_uc;
	size_t			i;

	dest_to_uc = (unsigned char *)dest;
	src_to_uc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_to_uc[i] = src_to_uc[i];
		if (src_to_uc[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
