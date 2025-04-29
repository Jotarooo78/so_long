/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:10:51 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/29 15:32:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*src;
	int		len;

	len = 0;
	ch = (char)c;
	src = (char *)s;
	while (src[len])
		len++;
	while (len != 0)
	{
		if (src[len] == ch)
			return (&src[len]);
		len--;
	}
	if (src[0] == ch)
		return (&src[0]);
	return (0);
}
/*
int	main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_printf("%s\n", ft_strrchr(av[1], av[2][0]));
		ft_printf("%s\n", strrchr(av[1], av[2][0]));
	}
	return (0);
}
*/
