/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:30:50 by avallete          #+#    #+#             */
/*   Updated: 2015/01/11 13:09:08 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_printf.h>

void	fill_it(t_flags *flags, int size)
{
	if (flags->optzero && !(flags->prec))
		ft_filler('0', size);
	else
		ft_filler(' ', size);
}

void	print_plus(t_flags *flags, int *i, int c)
{
		if (flags->optplus && c > 0)
		{
			ft_putchar('+');
			i[1] += 1;
		}
}

void	print_int_opt(t_flags *flags, int c, int size, int *i)
{
	i[1] += flags->min_size - size;
	if (flags->optmin)
	{
		print_plus(flags, i, c);
		if (flags->prec)
			ft_filler('0', flags->prec - ft_nbrlen(c));
		ft_putnbr(c);
		fill_it(flags, flags->min_size - size);
	}
	else
	{
		fill_it(flags, flags->min_size - size);
		print_plus(flags, i, c);
		if (flags->prec)
			ft_filler('0', flags->prec - ft_nbrlen(c));
		ft_putnbr(c);
	}
}

int		print_int_fill(t_flags *flags, int *i, int c)
{
	int size;

	size = ft_nbrlen(c);
	if (flags->prec)
		size += (flags->prec - size);
	if (flags->optplus && c > 0)
		size += 1;
	if (flags->min_size && size < flags->min_size)
		print_int_opt(flags, c, size, i);
	if (flags->optplus && c > 0)
		size -= 1;
	return (size);
}


void	print_int(t_flags *flags, va_list list, int *i)
{
	int c;
	int size;

	c = va_arg(list, int);
	if (flags->prec || flags->min_size)
		size = print_int_fill(flags, i, c);
	else
	{
		size = ft_nbrlen(c);
		ft_putnbr(c);
	}
	i[1] += size;
}

void	arg_is_int(t_flags *flags, va_list list, int *i)
{

	if ((flags->type == 'd' || flags->type == 'i') && flags->formf == 'l')
		flags = flags;
	else
		print_int(flags, list, i);
}
