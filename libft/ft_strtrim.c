/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:31:13 by armosnie          #+#    #+#             */
/*   Updated: 2024/12/02 14:11:28 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	set_check(char const *charset, char c)
{
	size_t	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	len;

	start = 0;
	end = ft_strlen(s1);
	i = -1;
	if (!set || !s1)
		return (ft_strdup(""));
	while (set_check(set, s1[start]) == 1)
		start++;
	while (set_check(set, s1[end - 1]) == 1)
		end--;
	len = end - start;
	if (start == len)
		return (ft_strdup(""));
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (ft_strdup(""));
	while (++i < len)
		res[i] = s1[start + i];
	return (res[i] = '\0', res);
}
