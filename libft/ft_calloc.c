/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:33:05 by armosnie          #+#    #+#             */
/*   Updated: 2024/11/28 17:43:25 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (nmemb == INT_MAX && size == INT_MAX)
		return (NULL);
	res = malloc(nmemb * size);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, nmemb * size);
	return (res);
}

// int	main(int ac, char **av)
// {
// 	int i = 0;
// 	char *res = ft_calloc(atoi(av[1]), atoi(av[2]));
// 	if (ac == 3)
// 	{
// 		while (i < atoi(av[2]))
// 		{
// 			printf("%c\n", res[i]);
// 			i++;
// 		}
// 	}
// 	return (0);
// }
