/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_o.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 11:16:08 by avallete          #+#    #+#             */
/*   Updated: 2015/01/12 13:32:01 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_linttoct(unsigned long int nb, char *str)
{
	const int	mask2 = (7 << 0);
	int 		i;

	i = 1;
	if (nb > 0)
	{
		while ((nb >> (3 * i)) > 0)
			i++;
		while (nb > 0)
		{
			str[i - 1] = '0' + (nb & mask2);
			i--;
			nb >>= 3;
		}
	}
	else
		str[0] = '0';
}

void	print_octal(va_list list, int *i)
{
	unsigned long int pt;
	char str[100];

	ft_bzero(str, 100);
	pt = va_arg(list, unsigned long int);
	ft_linttoct(pt, str);
	ft_putstr(str);
	i[1] += ft_strlen(str);
}

void	arg_is_octal(t_flags *flags, va_list list, int *i)
{
	if (flags->type == 'o' || flags->type == 'O')
		print_octal(list, i);
}
