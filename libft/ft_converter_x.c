/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 10:37:29 by avallete          #+#    #+#             */
/*   Updated: 2015/01/12 11:13:35 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_inttohexa(unsigned long int nb, char *str, char *hex)
{
	int i;

	i = 1;
	if (nb > 0)
	{
		while ((nb >> (4 * i)) > 0 && i < 16)
			i++;
		i--;
		while (nb > 0)
		{
			str[i--] = hex[(nb & 0xF)];
			nb >>= 4;
		}
	}
	else
		str[0] = '0';
}

void	print_x(t_flags *flags, va_list list, int *i)
{
	unsigned long int pt;
	char str[16];

	flags = flags;
	ft_bzero(str, 16);
	pt = va_arg(list, unsigned long int);
	flags->type == 'x' ? ft_inttohexa(pt, str, HEXMIN) :\
	ft_inttohexa(pt, str, HEXMAJ);
	ft_putstr(str);
	i[1] += ft_strlen(str);
}

void	arg_is_x(t_flags *flags, va_list list, int *i)
{
	if (flags->type == 'x' || flags->type == 'X')
		print_x(flags, list, i);
}
