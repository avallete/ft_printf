/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 13:35:01 by avallete          #+#    #+#             */
/*   Updated: 2015/01/14 15:13:58 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_putlnbr(unsigned long long int nbr)
{
	if (nbr <= 9)
		ft_putchar(nbr + '0');
	else
	{
		ft_putlnbr(nbr / 10);
		ft_putlnbr(nbr % 10);
	}
}

int		ft_lnbrlen(unsigned long long int nbr)
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

void  cast_unsigned(unsigned long long int *c, va_list list, t_flags *flags)
{
  if (flags->formf == 'h' && flags->formt == 'h')
    *c = (unsigned char)va_arg(list, int);
  else if (flags->formf == 'h' && flags->formt == '\0')
    *c = (unsigned short)va_arg(list, int);
  else
    *c = va_arg(list, unsigned long long int);
}

void	print_unsigned(t_flags *flags, va_list list, int *i)
{
	unsigned long long int	pt;

  cast_unsigned(&pt, list, flags);
	ft_putlnbr(pt);
	i[1] += ft_lnbrlen(pt);
}

void	arg_is_unsigned(t_flags *flags, va_list list, int *i)
{
	if (flags->type == 'u' || flags->type == 'U')
		print_unsigned(flags, list, i);
}
