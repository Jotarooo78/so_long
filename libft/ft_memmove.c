/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:13:42 by armosnie          #+#    #+#             */
/*   Updated: 2024/11/28 19:00:49 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	if (dest > src)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}
/*
int	main(void)
{
	char *src = "rem ipssum dolor sit a";
	char dest[ft_strlen(src)];
	printf("%s",(char *)memmove(src, dest, 8));
	printf("%s\n",(char *)ft_memmove(src, dest, 8));
	if (src != ft_memmove(src, dest, 8))
		write(1, "dest's adress was not returned\n", 31);
  write(1, dest, 22);
}*/
