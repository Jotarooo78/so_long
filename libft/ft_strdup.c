/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:19:13 by armosnie          #+#    #+#             */
/*   Updated: 2024/11/14 17:03:59 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dup == NULL)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
int	main(int ac, char **av)
{
	char	*dup = ft_strdup(av[1]);
	char	*dupv2 = strdup(av[1]);
	if (ac == 2)
	{
		printf("%s\n", dup);
		printf("%s\n", dupv2);
	}
	free (dup);
	free (dupv2);
	return (0);
}*/
