/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizsurmeli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:35:08 by denizsurmeli      #+#    #+#             */
/*   Updated: 2022/06/22 17:15:10 by denizsurmeli     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strncpy(char *dest, const char *src, size_t l)
{
	size_t	i;

	i = 0;
	while (i < l && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < l)
		dest[i++] = '\0';
	return (dest);
}
