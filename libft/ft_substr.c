/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:29:01 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/29 15:32:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	char	*res;

	str = (char *)s;
	i = 0;
	if (len == 0 || s == NULL || start > (size_t)ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = str[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

// int main()
// {	char *str = "01234";
// 	size_t size = 10;
// 	char *ret = ft_substr(str, 10, size);

// 	if (!strncmp(ret, "", 1))
// 	{
// 	free(ret);
// 	exit(ft_printf("TEST_SUCCESS"));
// 	}
// 	free(ret);
// 	exit(ft_printf("TEST_FAILED"));
// }
// int	main(int ac, char **av)
// {
// 	char	*res;

// 	res = ft_substr(av[1], atoi(av[2]), atoi(av[3]));
// 	if (ac == 4)
// 	{
// 		ft_printf("%s\n", res);
// 	}
// 	free(res);
// 	return (0);
// }
