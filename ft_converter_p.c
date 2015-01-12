/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 14:49:51 by avallete          #+#    #+#             */
/*   Updated: 2015/01/12 10:14:59 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_longinttohexa(unsigned long int nb, char *str, char *hex)
{
	int i;

	i = 13;
	while (nb > 0)
	{
		str[i--] = hex[(nb & 0xF)];
		nb >>= 4;
	}
}

void	print_ptr(va_list list, int *i)
{
	unsigned long int pt;
	char str[] = OXMIN;

	pt = va_arg(list, unsigned long int);
	ft_longinttohexa(pt, str, HEXMIN);
	ft_putstr(str);
	i[1] += ft_strlen(str);
}

void	arg_is_ptr(t_flags *flags, va_list list, int *i)
{
	if (flags->type == 'p')
		print_ptr(list, i);
}
