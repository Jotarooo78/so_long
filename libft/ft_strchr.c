/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:48:51 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/17 16:40:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*src;
	char	ch;

	ch = (char)c;
	src = (char *)s;
	i = 0;
	while (src[i])
	{
		if (src[i] == ch)
			return (&src[i]);
		i++;
	}
	if (ch == '\0')
		return (&src[i]);
	return (0);
}
