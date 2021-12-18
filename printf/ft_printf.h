/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:07:57 by nlenoch           #+#    #+#             */
/*   Updated: 2021/08/17 18:39:30 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>

int	ft_printf(const char *input, ...);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int nbr);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_puthex(unsigned long n, char prc);

#endif
