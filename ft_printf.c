/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:33:13 by nlenoch           #+#    #+#             */
/*   Updated: 2021/08/17 20:58:07 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(char c, va_list arg)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(arg, unsigned int), c));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		return (ft_puthex(va_arg(arg, unsigned long), c));
	}
	else if (c == 'u')
		return (ft_putunbr(va_arg(arg, unsigned int)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	arg;
	int		print;

	print = 0;
	va_start (arg, input);
	while (*input != '\0')
	{
		if (*input == '%')
		{
			print += ft_convert(*(++input), arg);
			if (!(*input))
				break ;
		}
		else
			print += ft_putchar(*input);
		input++;
	}
	va_end (arg);
	return (print);
}
