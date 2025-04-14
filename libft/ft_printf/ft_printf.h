/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:48:41 by armosnie          #+#    #+#             */
/*   Updated: 2024/12/05 12:47:56 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(const char *str);
int	ft_putnbr_base(long n, char *base, int baselen);
int	check_argument(void *n);
int	ft_strlen(const char *str);
int	ft_printf(const char *str, ...);
int	ft_unsigned_putnbr_base(unsigned long n, char *base, int baselen);

#endif