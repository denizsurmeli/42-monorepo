/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizsurmeli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:35:10 by denizsurmeli      #+#    #+#             */
/*   Updated: 2022/06/22 17:15:11 by denizsurmeli     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	if (haystack == NULL || needle == NULL)
		return (0);
	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] != '\0')
		{
			if (needle[j] == haystack[i + j])
				j++;
			else
				break ;
		}
		if (j == ft_strlen(needle))
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
