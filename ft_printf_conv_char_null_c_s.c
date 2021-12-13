/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_char_NULL_c_s.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:35:40 by mbagg             #+#    #+#             */
/*   Updated: 2021/12/11 19:00:12 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(char f)
{
	write(1, &f, 1);
	return (1);
}

int	ft_printf_null(void)
{
	write(1, "(null)", 6);
	return (6);
}

int	ft_printf_conv_c(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int	ft_printf_conv_s(va_list ap)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(ap, char *);
	if (s == 0)
	{
		i = ft_printf_null();
		return (i);
	}
	if (!s[0])
		return (0);
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
