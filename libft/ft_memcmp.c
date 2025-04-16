/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:09:16 by armosnie          #+#    #+#             */
/*   Updated: 2024/11/20 15:49:37 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*t1;
	unsigned char	*t2;
	size_t			i;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (t1[i] != t2[i])
			return (t1[i] - t2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;
// 	size_t	size;
// 	int		i1;
// 	int		i2;

// 	s1 = "\xff\xaa\xde\x12";
// 	s2 = "\xff\xaa\xde\x12MA";
// 	size = 4;
// 	i1 = ((memcmp(s1, s2, size) > 0) ? 1 : ((memcmp(s1, s2, size) < 0) ?
// 				-1 : 0));
// 	i2 = ((ft_memcmp(s1, s2, size) > 0) ? 1 : ((ft_memcmp(s1, s2, size) < 0) ?
// 				-1 : 0));
// 	printf("i1  = %d\n", i1);
// 	printf("i2  = %d\n", i2);
// 	if (i1 == i2)
// 		exit(printf("TEST_SUCCESS"));
// 	exit(printf("TEST_FAILED"));
// }
