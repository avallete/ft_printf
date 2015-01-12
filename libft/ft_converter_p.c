/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 14:49:51 by avallete          #+#    #+#             */
/*   Updated: 2015/01/12 10:35:12 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_linttohexa(unsigned long int nb, char *str, char *hex)
{
	int e;

	e = 1;
	while ((nb >> 4 * e) > 0)
		e++;
	while (nb > 0)
	{
		str[e-- + 1] = hex[(nb & 0xF)];
		nb >>= 4;
	}
}

void	print_ptr(va_list list, int *i)
{
	unsigned long int pt;
	char str[] = OXMIN;

	ft_bzero(str + 2, 12);
	pt = va_arg(list, unsigned long int);
	ft_linttohexa(pt, str, HEXMIN);
	ft_putstr(str);
	i[1] += ft_strlen(str);
}

void	arg_is_ptr(t_flags *flags, va_list list, int *i)
{
	if (flags->type == 'p')
		print_ptr(list, i);
}
