/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_i_d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:35:55 by mbagg             #+#    #+#             */
/*   Updated: 2021/12/11 19:00:16 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_conv_id_length(int n, int i)
{
	while (n > 9 || n < -9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_printf_conv_id_rec(int i, int n, int min, char *x)
{
	while (i >= 0)
	{
		x[i] = (n % 10 * min) + '0';
		n = n / 10;
		i--;
	}
}

int	ft_printf_conv_id(va_list ap)
{
	int		n;
	int		min;
	int		i;
	char	x[20];

	n = va_arg(ap, int);
	min = 1;
	i = 0;
	if (n < 0)
	{
		min = -1;
		ft_printf_char('-');
	}
	i = ft_printf_conv_id_length(n, i);
	x[i + 1] = 0;
	ft_printf_conv_id_rec(i, n, min, &x[0]);
	i = 0;
	while (x[i])
	{
		i = i + ft_printf_char(x[i]);
	}
	if (min == -1)
		i++;
	return (i);
}
