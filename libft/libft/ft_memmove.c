/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizsurmeli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:15:00 by denizsurmeli      #+#    #+#             */
/*   Updated: 2022/06/22 17:15:02 by denizsurmeli     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*d_to_uc;
	unsigned char	*s_to_uc;

	d_to_uc = (unsigned char *)dest;
	s_to_uc = (unsigned char *)src;
	if (dest == src)
		return (dest);
	if (s_to_uc < d_to_uc)
	{
		while (len--)
			*(d_to_uc + len) = *(s_to_uc + len);
		return (dest);
	}
	while (len--)
		*d_to_uc++ = *s_to_uc++;
	return (dest);
}
