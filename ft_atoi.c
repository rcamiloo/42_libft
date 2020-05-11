/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 20:44:28 by cda-silv          #+#    #+#             */
/*   Updated: 2020/05/10 02:59:20 by cda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_space(int c)
{
	if (c == '\n' || c == ' ' || c == '\v' || c == '\t'
			|| c == '\r' || c == '\f')
		return (1);
	else
		return (0);
}

static int	ft_overlimit(long n, int sinal)
{
	if (n > INT_MAX)
	{
		if (sinal == 1)
			return (1);
		else if (n - 1 > INT_MAX)
			return (-1);
	}
	return (0);
}

int		ft_atoi(const char *str)
{
	int res;
	int sinal;

	sinal = 1;
	res = 0;
	while (ft_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		sinal = (*str == '-') ? -1 : 1;
		str++;
	}
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			res = (res * 10) + (*str - '0');
			str++;
			if (ft_overlimit(res, sinal))
				return (ft_overlimit(res, sinal) == 1 ? -1 : 0);
		}
		else 
			return (sinal * (int)res);
	}
	return (sinal * (int)res);
}
