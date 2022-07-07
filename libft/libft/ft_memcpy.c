/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizsurmeli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 22:58:45 by denizsurmeli      #+#    #+#             */
/*   Updated: 2022/06/22 17:15:02 by denizsurmeli     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_to_char;
	unsigned char	*src_to_char;

	if ((dest == src) || n == 0)
		return (dest);
	if ((src == NULL) || (dest == NULL))
		return (NULL);
	i = 0;
	dest_to_char = (unsigned char *)dest;
	src_to_char = (unsigned char *)src;
	while (i < n)
	{
		dest_to_char[i] = src_to_char[i];
		i++;
	}
	return (dest = dest_to_char);
}
