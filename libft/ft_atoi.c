/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:01:03 by armosnie          #+#    #+#             */
/*   Updated: 2024/11/14 16:59:55 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nbr)
{
	char	*nb;
	int		i;
	int		res;
	int		neg;

	nb = (char *)nbr;
	i = 0;
	res = 0;
	neg = 1;
	while ((nb[i] >= 9 && nb[i] <= 13) || nb[i] == 32)
		i++;
	if (nb[i] == '-' || nb[i] == '+')
	{
		if (nb[i] == '-')
			neg *= -1;
		i++;
	}
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		res = (res * 10) + nb[i] - '0';
		i++;
	}
	return (res * neg);
}
/*
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("%d\n", ft_atoi(av[1]));
		printf("%d\n", atoi(av[1]));
	}
	return (0);
}*/
