/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:35:49 by armosnie          #+#    #+#             */
/*   Updated: 2024/11/28 19:14:39 by armosnie         ###   ########.fr       */
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
		exit(printf("TEST_SUCCESS"));
	exit(printf("TEST_FAILED"));
}
*/
/*
int	main(int ac, char **av)
{
	if (ac == 4)
	{
		printf("%s\n", (char *)ft_memchr(av[1], av[2][0], atoi(av[3])));
		printf("- \n%s", (char *)memchr(av[1], av[2][0], atoi(av[3])));
	}
	return (0);
}*/
