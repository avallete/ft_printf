/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:42:04 by avallete          #+#    #+#             */
/*   Updated: 2015/01/13 18:00:35 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_printf.h>

void	print_string(va_list list, int *i)
{
	char *str;

	str = NULL;
	str = va_arg(list, char*);
	str ? ft_putstr(str) : ft_putstr("(null)");
	str ? (i[1] += ft_strlen(str)) : (i[1] += 6);
}

void	arg_is_string(t_flags *flags, va_list list, int *i)
{
	if ((flags->type == 's' && flags->formf == 'l') || flags->type == 'S')
		arg_is_wstr(flags, list, i);
	else
		print_string(list, i);
}
