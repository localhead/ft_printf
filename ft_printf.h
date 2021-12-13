/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:35:16 by mbagg             #+#    #+#             */
/*   Updated: 2021/12/11 19:00:09 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<unistd.h>
# include	<stdarg.h>

void	ft_printf_conv_id_rec(int i, int n, int min, char *x);
void	ft_printf_conv_u_rec(int i, unsigned int n, char *x);
void	ft_printf_conv_p_x_xx_write(char *a, int j);
int		ft_printf(const char *f, ...);
int		ft_printf_start(const char *f, va_list ap);
int		ft_printf_conversions(const char f, va_list ap);
int		ft_printf_char(char f);
int		ft_printf_null(void);
int		ft_printf_conv_c(va_list ap);
int		ft_printf_conv_s(va_list ap);
int		ft_printf_conv_id(va_list ap);
int		ft_printf_conv_id_length(int n, int i);
int		ft_printf_conv_u(va_list ap);
int		ft_printf_conv_u_length(int i, unsigned int n);
int		ft_printf_conv_p(va_list ap);
int		ft_printf_conv_p_x_rec(unsigned long long int decimal, char *a);
int		ft_printf_conv_x(va_list ap);
int		ft_printf_conv_xx(va_list ap);

#endif