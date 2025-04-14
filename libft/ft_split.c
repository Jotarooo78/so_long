/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:56:39 by armosnie          #+#    #+#             */
/*   Updated: 2024/12/02 14:12:36 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	*dup_word(const char *s, char c)
{
	int		i;
	char	*dup;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	dup = malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static void	free_all(char **split)
{
	int	j;

	j = 0;
	while (split[j])
	{
		free(split[j]);
		j++;
	}
	free(split);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	int		j;
	int		i;

	i = 0;
	j = 0;
	split = malloc(sizeof(char *) * (count_words((char *)s, c) + 1));
	if (split == NULL || s == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			split[j] = dup_word(&s[i], c);
			if (split[j++] == NULL)
				return (free_all(split), NULL);
			while (s[i] && s[i] != c)
				i++;
		}
		else
			break ;
	}
	return (split[j] = NULL, split);
}

// int	main(int ac, char **av)
// {
// 	int		j;
// 	char	**res;

// 	(void)ac;
// 	j = 0;
// 	res = ft_split((char *)av[1], ' ');
// 	if (ac == 2)
// 	{
// 		while (res[j])
// 		{
// 			printf("%s\n", res[j]);
// 			j++;
// 		}
// 	}
// 	free_all(res);
// 	return (0);
// }
