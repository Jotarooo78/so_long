/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:35:49 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/29 15:32:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	ch;
	size_t			i;

	src = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (src[i] == ch)
			return ((void *)&src[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	*src;
	int		size;

	src = "/|\x12\xff\x09\0\x42\042\0\42|\\";
		size = 12;
	if (memchr(src, '\0', size) == ft_memchr(src, '\0', size))
		exit(ft_printf("TEST_SUCCESS"));
	exit(ft_printf("TEST_FAILED"));
}
*/
/*
int	main(int ac, char **av)
{
	if (ac == 4)
	{
		ft_printf("%s\n", (char *)ft_memchr(av[1], av[2][0], atoi(av[3])));
		ft_printf("- \n%s", (char *)memchr(av[1], av[2][0], atoi(av[3])));
	}
	return (0);
}*/
