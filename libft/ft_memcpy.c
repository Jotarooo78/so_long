/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:31:02 by armosnie          #+#    #+#             */
/*   Updated: 2024/11/14 16:54:04 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = (char *)dest;
	s = (const char *)src;
	if (dest == NULL && src == NULL && n > 0)
		return (0);
	while (n)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return (d);
}
/*
int main(int ac, char **av)
{
	if (ac == 4)
	{
		printf("%s\n", (char *)ft_memcpy(av[1], av[2], atoi(av[3])));
		printf("%s\n", (char *)memcpy(av[1], av[2], atoi(av[3])));
	}
	return (0);
}*/
