/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 10:19:12 by avallete          #+#    #+#             */
/*   Updated: 2015/01/09 16:23:24 by avallete         ###   ########.fr       */
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

void	check_flg(char *str, t_flags *flags, int *i)
{
	if (str[*i + 1] == '#' || str[*i + 1] == '+' || str[*i + 1] == '0' || \
			str[*i+ 1] == '-' || str[*i + 1] == ' ')
	{
		while (str[*i + 1] == '#' || str[*i + 1] == '+' || str[*i + 1] == '0' || \
				str[*i+ 1] == '-' || str[*i + 1] == ' ')
		{
			str[*i + 1] == '#' ? (flags->optsharp = 1) : (flags->optsharp += 0);
			str[*i + 1] == '-' ? (flags->optmin = 1) : (flags->optmin += 0);
			str[*i + 1] == '+' ? (flags->optplus = 1) : (flags->optplus += 0);
			str[*i + 1] == '0' ? (flags->optzero = 1) : (flags->optzero += 0);
			str[*i + 1] == ' ' ? (flags->optspace = 1) : (flags->optspace += 0);
			*i++;
			i[1]++;
		}
	}
}

char	*ft_grep_first_number(char *str, int *i)
{
	char result[100];
	int	e;

	ft_bzero(result, 100);
	e = 0;
	while (ft_isdigit(str[*i]))
	{
		result[e] = str[*i];
		e++;
		*i++;
		i[1]++;
	}
	return (result);
}

void	check_width(char *str, t_flags *flags, int *i)
{
	char *nmb;

	if (flags->optzero)
		nmb = ft_grep_first_number(str, i);
}

void	init_flags(char *str, t_flags *flags, int *i)
{
	check_flg(str, flags, i);

}

void ft_arg_sort(const char *str, va_list list, int *i)
{
	t_flags flags;

	ft_bzero(&flags, sizeof(t_flags));
	init_flags(str, &flags, i);
}

int found_flags(const char *str, va_list list)
{
	int i[2];

	*i = 0;
	i[1] = 0;
	while (str[*i] != '\0')
	{
		if (str[*i] == '%')
			ft_arg_sort(str, list, i);
		else
			ft_putchar(str[*i]);
		*i += 1;
	}
	return (*i - i[1]);
}

int arg_is_string(va_list list)
{
	char *str;

	str = NULL;
	str = va_arg(list, char*);
	str ? ft_putstr(str) : ft_putstr("(null)");
	if (str)
		return (ft_strlen(str));
	return (6);
}

int arg_is_mod(const char *str, va_list list)
{
	if (*str == '%')
	{
		ft_putchar('%');
		return (2);
	}
	if (*str == 's')
		arg_is_string(list);
	return (1);
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
		if (ft_strchr(format, '%'))
			ret = found_flags(format, list);
		else
		{
			ft_putstr(format);
			ret = ft_strlen(format);
		}
	}
	return (ret);
}

int main(void)
{
	int ret1;
	int ret2;

	ret1 = printf("jolie test %    #####00000\n", 3);
	ret1 = ft_printf("jolie test %\n", "lalalalal");
	//	printf("%d -- %d\n", ret1, ret2);
	return (0);
}
