/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizsurmeli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:35:10 by denizsurmeli      #+#    #+#             */
/*   Updated: 2022/06/22 17:15:12 by denizsurmeli     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	mem = (char *)malloc((len + 1) * sizeof(char));
	if (mem == NULL || s == NULL)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			mem[j] = s[i];
			j++;
		}
		i++;
	}
	mem[j] = 0;
	return (mem);
}
