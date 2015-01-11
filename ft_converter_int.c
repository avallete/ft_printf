/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:30:50 by avallete          #+#    #+#             */
/*   Updated: 2015/01/11 11:14:17 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_printf.h>

void	print_int(va_list list, int *i)
{
	int c;

	c = va_arg(list, int);
	if (c >= 0 && c <= 255)
		ft_putchar((char)c);
	i[1] += 1;
}

void	arg_is_int(t_flags *flags, va_list list, int *i)
{
	if ((flags->type == 'd' || flags->type == 'i') && flags->formf == 'l')
		flags = flags;
	else
		print_int(list, i);
}
