/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:08:27 by armosnie          #+#    #+#             */
/*   Updated: 2024/11/21 11:45:29 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_lst;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst)
	{
		last_lst = ft_lstlast(*lst);
		last_lst->next = new;
	}
	else
		*lst = new;
}
// #include "libft.h"

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*last_lst;

// 	last_lst = 0;
// 	if (lst)
// 	{
// 		if (*lst)
// 			ft_lstlast(*lst)->next = new;
// 		else
// 			*lst = new;
// 	}
// }
