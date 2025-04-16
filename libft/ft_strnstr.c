/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:59:19 by armosnie          #+#    #+#             */
/*   Updated: 2024/11/18 15:57:20 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)&s1[i]);
	while (s1[i] && i < n)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (s1[i + j] == s2[j] && i + j < n)
			{
				j++;
				if (s2[j] == '\0')
					return ((char *)&s1[i]);
			}
		}
		i++;
	}
	return (0);
}
/*
int	main(int ac, char **av)
{
	if (ac == 4)
	{
		printf("%s\n", ft_strnstr(av[1], av[2], atoi(av[3])));
	}
	return (0);
}*/
