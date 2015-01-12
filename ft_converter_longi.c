/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_longi.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 16:17:42 by avallete          #+#    #+#             */
/*   Updated: 2015/01/12 17:13:31 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_putlongnbr(long int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 0 && nb <= 9)
		ft_putchar('0' + nb);
	else
	{
		ft_putlongnbr(nb / 10);
		ft_putlongnbr(nb % 10);
	}
}

int		ft_longnbrlen(long int nb)
{
	int i;

	i = 1;
	while (nb /= 10 > 0)
		i++
}

void	print_longint_opt(t_flags *flags, long int l, int size, int *i)
{
	i[1] += flags->min_size - size;
	if (flags->optmin)
	{
		flags->optmin && l > 0 ? ft_putchar('+'), i[1]++ : i[1] += 0;
		if (flags->prec)
			ft_filler('0', flags->prec - ft_longnbrlen(l));
		ft_putlongnbr(l);
		fill_it(flags, flags->min_size - size);
	}
	else
	{
		fill_it(flags, flags->min_size - size);
		flags->optmin && l > 0 ? ft_putchar('+'), i[1]++ : i[1] += 0;
		if (flags->prec)
			ft_filler('0', flags->prec - ft_longnbrlen(l));
		ft_putlongnbr(l);
	}
}

int		print_lint_fill(t_flags *flags, int *i, long int l)
{
	int	size;

	size = ft_longnbrlen(l);
	if (flags->prec)
		size += (flags->prec - size);
	if (flags->optplus && l > 0)
		size += 1;
	if (flags->min_size && size < flags->min_size)
		print_longint_opt(flags, l, size, i);
	if (flags->optplus && l > 0)
		size--;
	return (size);
}

void	print_longi(t_flags *flags, va_list list, int *i)
{
	long int	l;
	int			s;

	l = va_arg(list, long int);
	if (flags->prec || flags->min_size)
		size = print_lint_fill(flags, i, l);
	else
	{
		size = ft_longnbrlen(l);
		if (flags->optplus)
		{
			ft_putchar('+')
			size++;
		}
		ft_putlongnbr(l);
	}
	i[1] += size;
}

void	arg_is_longi(t_flags *flags, va_list list, int *i)
{
	print_longi(flags, list, i);
}
