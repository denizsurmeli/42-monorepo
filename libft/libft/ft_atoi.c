/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizsurmeli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:34:56 by denizsurmeli      #+#    #+#             */
/*   Updated: 2022/06/22 17:14:55 by denizsurmeli     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' \
			|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(const char *src)
{
	size_t	i;
	int		num;
	int		sign;

	sign = 1;
	num = 0;
	i = 0;
	while (is_whitespace(src[i]))
		i++;
	if (src[i] == '-' || src[i] == '+')
	{
		if (src[i] == '-')
			sign = -1;
		i++;
	}
	while (src[i] >= '0' && src[i] <= '9')
	{
		num = (num * 10) + (src[i] - '0');
		i++;
	}
	return (num * sign);
}
