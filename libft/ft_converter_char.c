/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 10:34:27 by avallete          #+#    #+#             */
/*   Updated: 2015/01/14 13:10:22 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_printf.h>

void	print_char(va_list list, int *i)
{
	int c;

	c = va_arg(list, int);
	if (c >= 0 && c <= 255)
		ft_putchar((char)c);
	i[1] += 1;
}

void	arg_is_char(t_flags *flags, va_list list, int *i)
{
	if (flags->type == 'C' || flags->formf == 'l')
		arg_is_wchar(flags, list, i);
	else
		print_char(list, i);
}
