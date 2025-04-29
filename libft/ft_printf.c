/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:34:48 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/29 15:46:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	which_percent(size_t i, va_list(list))
{
	if (i == 'd')
		return (ft_putnbr_base(va_arg(list, int), "0123456789", 10));
	else if (i == 'u')
		return (ft_unsigned_putnbr_base(va_arg(list, unsigned int),
				"0123456789", 10));
	else if (i == 's')
		return (ft_putstr(va_arg(list, const char *)));
	else if (i == 'c')
		return (ft_putchar(va_arg(list, int)));
	else if (i == 'i')
		return (ft_putnbr_base(va_arg(list, int), "0123456789", 10));
	else if (i == 'p')
		return (check_argument(va_arg(list, void *)));
	else if (i == 'x')
		return (ft_putnbr_base(va_arg(list, unsigned int), "0123456789abcdef",
				16));
	else if (i == 'X')
		return (ft_putnbr_base(va_arg(list, unsigned int), "0123456789ABCDEF",
				16));
	else if (i == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar('%') + ft_putchar(i));
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	size_t	i;
	size_t	len;

	va_start(list, str);
	i = 0;
	len = 0;
	if (str == 0)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			len += which_percent(str[i], list);
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (len);
}

// int	main(void)
// {
// 	ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
// 	ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
// 	ft_printf("\n");
// 	ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
// 	ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
// }