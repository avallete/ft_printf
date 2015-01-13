/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_S.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 17:58:47 by avallete          #+#    #+#             */
/*   Updated: 2015/01/13 18:11:15 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_putwstr(wchar_t *str)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		i += ft_putwchar(*str);
		str++;
	}
	return (i);
}

void	print_wstr(t_flags *flags, va_list list, int *i)
{
	wchar_t	*str;

	flags = flags;
	str = va_arg(list, wchar_t*);
	str ? (i[1] += ft_putwstr(str)) : (ft_putstr("(null)"), i[1] += 6);
}

void	arg_is_wstr(t_flags *flags, va_list list, int *i)
{
	print_wstr(flags, list, i);
}
