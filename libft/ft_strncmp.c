/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:19:02 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/29 15:32:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	int				size;
	unsigned char	*t1;
	unsigned char	*t2;

	i = 0;
	size = (int)n;
	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	if (size == i)
		return (0);
	if (size < 0)
		return (-1);
	while (t1[i] && t2[i] && t1[i] == t2[i] && i < size - 1)
		i++;
	return (t1[i] - t2[i]);
}
/*
int	main(void)
{
	char s1[] = "\200";
	char s2[] = "\0";
	ft_printf("%d\n", ft_strncmp(s1, s2, 1));
	ft_printf("%d\n", strncmp(s1, s2, 1));
	}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		ft_printf("%d\n", ft_strncmp(av[1], av[2], atoi(av[3])));
		ft_printf("%d\n", strncmp(av[1], av[2], atoi(av[3])));
	}
	return (0);
}*/
