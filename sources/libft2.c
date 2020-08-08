/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 18:14:09 by plettie           #+#    #+#             */
/*   Updated: 2020/08/08 18:14:13 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

void	ft_putstr_fd(char const *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	}
}

void	*ft_memalloc(size_t size)
{
	void	*memo;

	if ((memo = malloc(size)))
		ft_bzero(memo, size);
	return (memo);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	int		result;

	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		result = 0;
	else if (*s1 >= 0 && *s2 >= 0)
		result = *s1 - *s2;
	else
		result = *s2 - *s1;
	return (result);
}

int		ft_tolower(int item)
{
	if (item >= 'A' && item <= 'Z')
		return (item + 'a' - 'A');
	return (item);
}
