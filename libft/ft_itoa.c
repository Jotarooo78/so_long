/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:41:31 by armosnie          #+#    #+#             */
/*   Updated: 2024/11/18 13:24:46 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	get_len(long n)
{
	long	len;

	len = 1;
	if (n == 0)
		return (len + 1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	len;
	char	*res;
	long	nb;

	nb = n;
	len = get_len(nb);
	res = malloc(sizeof(char) * (len));
	if (res == NULL)
		return (NULL);
	if (nb == 0)
		res[0] = '0';
	res[--len] = '\0';
	len--;
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		res[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (res);
}
