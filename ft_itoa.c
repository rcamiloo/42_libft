/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamilo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:19:09 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/02/13 20:12:55 by rcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	char	*string;
	int		isnegative;
	long	i;
	long	new;

	i = n;
	len = (n == 0) ? 1 : 0;
	new = n;
	isnegative = 0;
	while (i)
	{
		len++;
		i = i / 10;
	}
	if (n < 0)
	{
		len++;
		new = -new;
		isnegative = 1;
	}
	if (!(string = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (i < len - isnegative)
	{
		string[i] = new % 10 + '0';
		new = new / 10;
		i++;
	}
	string[len - 1] = (isnegative == 1) ? '-' : string[len - 1];
	string[len] = '\0';
	ft_revstr(string);
	return (string);
}
