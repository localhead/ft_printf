/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:35:43 by mbagg             #+#    #+#             */
/*   Updated: 2021/12/11 18:18:30 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_conv_u_length(int i, unsigned int n)
{
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_printf_conv_u_rec(int i, unsigned int n, char *x)
{
	while (i >= 0)
	{
		x[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
}

int	ft_printf_conv_u(va_list ap)
{
	unsigned int	n;
	int				i;
	char			x[20];

	i = 0;
	n = va_arg(ap, unsigned int);
	i = ft_printf_conv_u_length(i, n);
	x[i + 1] = 0;
	ft_printf_conv_u_rec(i, n, &x[0]);
	i = 0;
	while (x[i])
	{
		i = i + ft_printf_char(x[i]);
	}
	return (i);
}
