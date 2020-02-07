/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamilo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 21:24:22 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/01/24 21:57:40 by rcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	if (c == '\n' || c == ' ' || c == '\v' || c == '\t'
			|| c == '\r' || c == '\f')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int signal;
	int result;

	signal = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		signal = (*str == '-') ? -1 : 1;
		str++;
	}
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			result = result * 10 + (*str - '0');
			str++;
		}
		else
			return (signal * result);
	}
	return (signal * result);
}
