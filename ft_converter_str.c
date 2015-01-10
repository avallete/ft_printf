/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:42:04 by avallete          #+#    #+#             */
/*   Updated: 2015/01/10 16:49:04 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_printf.h>
# include <stdio.h>

int arg_is_string(t_flags *flags, va_list list, int *i)
{
	char *str;

	str = NULL;
	str = va_arg(list, char*);
	str ? ft_putstr(str) : ft_putstr("(null)");
	i[0] += 1;
	str ? (i[1] += ft_strlen(str)) : (i[1] += 6);
}


