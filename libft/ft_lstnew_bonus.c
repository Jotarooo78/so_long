/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:14:19 by armosnie          #+#    #+#             */
/*   Updated: 2024/11/28 19:14:25 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*
int	main(void)
{
	t_list *new;

	new = ft_lstnew("Hello, world!");
	if (new != NULL)
	{
		printf("Content: %s\n", (char *)new->content);
		printf("Next: %p\n", new->next);
	}
	else
		printf("Failed to allocate memory.\n");
	free(new);

	return (0);
}*/
