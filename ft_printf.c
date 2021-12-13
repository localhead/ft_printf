/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:37:51 by mbagg             #+#    #+#             */
/*   Updated: 2021/12/11 19:03:45 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_conversions(const char f, va_list ap)
{
	int	res;

	res = 0;
	if (f == '%')
		res = ft_printf_char('%');
	if (f == 'c')
		res = ft_printf_conv_c(ap);
	if (f == 's')
		res = ft_printf_conv_s(ap);
	if (f == 'i' || f == 'd')
		res = ft_printf_conv_id(ap);
	if (f == 'u')
		res = ft_printf_conv_u(ap);
	if (f == 'p')
	{
		res = ft_printf_char('0') + ft_printf_char('x');
		res = res + ft_printf_conv_p(ap);
	}
	if (f == 'X')
		res = ft_printf_conv_xx(ap);
	if (f == 'x')
		res = ft_printf_conv_x(ap);
	return (res);
}

int	ft_printf_start(const char *f, va_list ap)
{
	int	i;
	int	res;
	int	tmp;

	i = 0;
	res = 0;
	tmp = 0;
	while (f[i])
	{
		tmp = 0;
		if (f[i] == '%' && f[i + 1])
		{
			tmp = ft_printf_conversions(f[i + 1], ap);
			i++;
		}
		else if (f[i] != '%')
			res = res + ft_printf_char(f[i]);
		i++;
		res = res + tmp;
	}
	return (res);
}

int	ft_printf(const char *f, ...)
{
	va_list	ap;
	int		res;

	va_start (ap, f);
	res = ft_printf_start(f, ap);
	va_end(ap);
	return (res);
}
