/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 13:35:01 by avallete          #+#    #+#             */
/*   Updated: 2015/01/12 13:40:28 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_print_long(long int nb, char)

void	print_unsigned(va_list list, int *i)
{
	unsigned long int pt;

	ft_bzero(str, 100);
	pt = va_arg(list, unsigned long int);
	ft_putnbr(pt);
	i[1] += ft_nbrlen(str);
}

void	arg_is_octal(t_flags *flags, va_list list, int *i)
{
	if (flags->type == 'o' || flags->type == 'O')
		print_octal(list, i);
}
