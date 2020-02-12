/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamilo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:46:07 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/02/12 19:02:34 by rcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nb_tokens(char const *s, char c)
{
	size_t		nb_tokens;
	char const	*inf_limit;
	char const	*sup_limit;

	nb_tokens = 0;
	inf_limit = s;
	sup_limit = s;
	while (*sup_limit)
	{
		inf_limit = sup_limit;
		sup_limit = ft_strchr(inf_limit + 1, c);
		if (!sup_limit)
			break ;
		if (sup_limit - inf_limit > 1)
			nb_tokens++;
	}
	return (nb_tokens);
}

size_t	ft_strclen(const char *s, char c)
{
	size_t size;

	size = 0;
	while (*s && (*s != c))
	{
		size++;
		s++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	size_t	nb_tokens;
	size_t	i;
	size_t	size_token;
	char	**result;

	if (!s)
		return (NULL);
	nb_tokens = ft_nb_tokens(s, c) + 1;
	result = malloc(sizeof(char *) * nb_tokens + 1);
	if (!result)
		return (NULL);
//	if (nb_tokens == 1)
//		return (NULL);
	i = 0;
	while (i < nb_tokens && *s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			size_token = ft_strclen(s, c);
			result[i] = (char *)malloc(sizeof(char) * size_token + 1);
			if (!result[i])
				return (NULL);
			ft_memcpy(result[i], s, size_token);
			result[i][size_token] = '\0';
			s = s + size_token;
		}
		i++;
	}
	result[nb_tokens] = NULL;
	return (result);
}
