/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:24:35 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/29 15:32:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

// void	printlist(t_list *a)
// {
// 	while ((char *)a)
// 	{
// 		ft_printf("%s\n", (char *)a->content);
// 		a = a->next;
// 	}
// }

// int	main(void)
// {
// 	t_list	*a;

// 	a = ft_lstnew("debut");
// 	ft_printf("adresse a main v0 %p\n", a);
// 	printlist(a);
// 	ft_printf("adresse a main v1 %p\n", a);
// 	ft_lstadd_front(&a, ft_lstnew("nouveau_deb"));
// 	ft_lstadd_front(&a, ft_lstnew("noveau_deb"));
// 	ft_lstadd_front(&a, ft_lstnew("nuveau_deb"));
// 	ft_lstadd_front(&a, ft_lstnew("ouveau_deb"));
// 	ft_lstadd_front(&a, ft_lstnew("noueau_deb"));
// 	ft_lstadd_front(&a, ft_lstnew("nouvau_deb"));
// 	ft_lstadd_front(&a, ft_lstnew("nouvu_deb"));
// 	// ft_printf("version 2\n");
// 	// printlist(a);
// 	// ft_printf("adresse a main v2 %p\n", a);
// 	// ft_lstremovefront(&a);
// 	// ft_printf("version 3\n");
// 	// ft_printf("adresse a main v3 %p\n", a);
// 	printlist(a);
// 	ft_printf("nbr de chaine dans la liste : %d\n", ft_lstsize(a)); //=8
// }
