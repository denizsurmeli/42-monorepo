/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizsurmeli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:36:32 by denizsurmeli      #+#    #+#             */
/*   Updated: 2022/06/22 17:15:03 by denizsurmeli     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memset(void *b, int c, size_t l)
{
	size_t			i;
	unsigned char	*b_to_uc;

	b_to_uc = (unsigned char *)b;
	i = 0;
	while (i < l)
	{
		b_to_uc[i] = (unsigned char)c;
		i++;
	}
	return (b = b_to_uc);
}
