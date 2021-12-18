/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:00:13 by nlenoch           #+#    #+#             */
/*   Updated: 2021/08/17 18:08:51 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(unsigned int n)
{
	int			i;

	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_putunbr(unsigned int n)
{
	char		c;
	int			i;

	i = ft_nbrlen(n);
	if (n > 9)
		ft_putunbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (i);
}
