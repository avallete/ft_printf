/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 14:49:51 by avallete          #+#    #+#             */
/*   Updated: 2015/01/11 17:52:21 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_inttohexa(unsigned long int nb, char *str)
{
	unsigned long int result;
	unsigned long int rest;

	rest = nb % 16;
	result = nb / 16;
	if (nb > 16)
		ft_inttohexa(result, str + 1);
	if (rest <= 9)
		*str = '0' + rest;
	else if (rest > 9 && rest < 16)
		*str = 'A' + rest - 9;
}

void	print_ptr(va_list list, int *i)
{
	unsigned long int pt;
	char str[100];

	ft_bzero(str, 100);
	str[0] = '0';
	str[1] = 'x';
	pt = va_arg(list, unsigned long int);
	ft_inttohexa(pt, str + 2);
	ft_putstr(str);
	i[1] += ft_strlen(str);
}

void	arg_is_ptr(t_flags *flags, va_list list, int *i)
{
	if (flags->type == 'p' && (flags->formf == 'l' || flags->optsharp))
		print_ptr(list, i);
	else
		print_ptr(list, i);
}
