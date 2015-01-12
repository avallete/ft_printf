/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 13:35:01 by avallete          #+#    #+#             */
/*   Updated: 2015/01/12 15:30:23 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_putlnbr(unsigned long int nbr)
{
	if (nbr <= 9)
		ft_putchar(nbr + '0');
	else
	{
		ft_putlnbr(nbr / 10);
		ft_putlnbr(nbr % 10);
	}
}

int		ft_lnbrlen(unsigned long int nbr)
{
	int i;

	i = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

void	print_unsigned(va_list list, int *i)
{
	unsigned long int	pt;

	pt = va_arg(list, unsigned long int);
	ft_putlnbr(pt);
	i[1] += ft_lnbrlen(pt);
}

void	arg_is_unsigned(t_flags *flags, va_list list, int *i)
{
	if (flags->type == 'u' || flags->type == 'U')
		print_unsigned(list, i);
}
