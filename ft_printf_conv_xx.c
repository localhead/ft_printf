/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_xx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:07:25 by mbagg             #+#    #+#             */
/*   Updated: 2021/12/11 19:08:19 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_conv_xx_rec(unsigned long long int decimal, char *a)
{
	unsigned long long int	quot;
	unsigned long long int	rem;
	int						j;

	quot = decimal;
	j = 0;
	while (quot != 0)
	{
		rem = quot % 16;
		if (rem < 10)
			a[j++] = 48 + rem;
		else
			a[j++] = 55 + rem;
		quot = quot / 16;
	}
	return (j);
}

int	ft_printf_conv_xx(va_list ap)
{
	unsigned int	decimal;
	int				i;
	int				j;
	char			a[100];

	decimal = va_arg(ap, unsigned int);
	if (decimal == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		j = ft_printf_conv_xx_rec(decimal, a);
	i = j;
	j = j - 1;
	ft_printf_conv_p_x_xx_write(a, j);
	return (i);
}
