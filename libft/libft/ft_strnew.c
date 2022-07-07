/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizsurmeli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:35:09 by denizsurmeli      #+#    #+#             */
/*   Updated: 2022/06/22 17:15:11 by denizsurmeli     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*loc;
	size_t	i;

	i = 0;
	loc = (char *)malloc((size + 1) * sizeof(char));
	if (loc == NULL)
		return (NULL);
	while (i < size + 1)
	{
		loc[i] = 0;
		i++;
	}
	return (loc);
}
