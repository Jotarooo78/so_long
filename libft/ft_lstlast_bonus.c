/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:17:10 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/29 15:32:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
// int	main()
// {
// 	t_list *l = ((void*)0);
// 	t_list *expected;
// 	t_list *actual;

// 	expected = ((void*)0);
// 	actual = ft_lstlast(l);
// 	if (actual == expected)S
// 		exit(ft_printf("TEST_SUCCESS"));
// 	exit(ft_printf("TEST_FAILED"));
// }