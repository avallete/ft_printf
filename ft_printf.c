/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 10:19:12 by avallete          #+#    #+#             */
/*   Updated: 2015/01/09 15:23:17 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_printf.h>
# include <stdio.h>

int check_exstr(const char *str)
{
	if (str != NULL && str[0] != '\0')
		return (1);
	else
		return (0);
}

int found_flags(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '%' && str[i] != '\0')
		ft_putchar(str[i++]);
	return (i);
}

int arg_is_mod(void)
{
	ft_putchar('%');
	return (2);
}

int arg_is_min(const char *str, va_list list)
{
	ft_arg_sort(str + 2, list);
	return (2);
}

int ft_arg_sort(const char *str, va_list list)
{
	int i;

	i = 1;
	if (*str == '%' && *(str + 1) == '%')
		return (arg_is_mod());
	if (*str == '-' && *(str + 1) == '-')
		return (arg_is_min(str, list));
	return (i);
}

int ft_arg_grep(const char *str, va_list list, int *ret)
{
	int i;

	i = 0;
	*ret += (i = found_flags(str));
	if (*str + i)
		*ret += (i += ft_arg_sort(str + i, list));
	return (i);
}

int ft_printf(const char *format, ...)
{
	va_list list;
	va_list cp;
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	if (check_exstr(format))
	{
		va_start(list, format);
		va_copy(cp, list);
		while (format[i] != '\0')
			i += ft_arg_grep(format + i, cp, &ret);
	}
	return (ret);
}

int main(void)
{
	int ret1;
	int ret2;

	ret1 = printf("jolie test %-0%%%%%%%%%%d%%%fdf\n", 3);
	ret1 = ft_printf("jolie test %-%%%%%%%%%%d%%%fdf\n", 3);
	//	printf("%d -- %d\n", ret1, ret2);
	return (0);
}
