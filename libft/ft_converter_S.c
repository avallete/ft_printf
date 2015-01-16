/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_S.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 17:58:47 by avallete          #+#    #+#             */
/*   Updated: 2015/01/16 10:33:43 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char  ft_wcharlen(wchar_t c)
{
  unsigned int e;

  e = (unsigned int)c;
  if (c >= 0 && c <= 255)
    return (1);
  else if (e > 255 && e < 0x10FFFF)
  {
    if (e < 0x07FF)
      return (2);
    else if (e < 0xFFFF)
      return (3);
    else
      return (4);
  }
  else
    return (1);
}

int   ft_wstrlen(wchar_t *str)
{
  int i;

  i = 0;
  while (*str != '\0')
  {
    i += ft_wcharlen(*str);
    str++;
  }
  return (i);
}

int   ft_wnstrlen(wchar_t *str, int n)
{
  int i;

  i = 0;
  while (*str != '\0' && i <= n)
  {
    i += ft_wcharlen(*str);
    str++;
  }
  return (i);
}
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

int		ft_putwnstr(wchar_t *str, int n)
{
  int i;

  i = 0;
  while (*str != '\0' && (i + ft_wcharlen(*str)) <= n)
  {
    i += ft_putwchar(*str);
    str++;
  }
  return (i);
}

void	print_wstr(t_flags *flags, va_list list, int *i)
{
  wchar_t	*str;
  int     size;

  size = 0;
  str = va_arg(list, wchar_t*);
  str ? (size = ft_wstrlen(str)) : (size += 6);
  if ((flags->optdot && flags->prec < size))
    size = flags->prec;
  if (!flags->optmin)
  {
    if (flags->min_size > size)
    {
      fill_it(flags, flags->min_size - size);
      size += flags->min_size - size;
    }
    if (flags->optdot && flags->prec)
      size += ft_putwnstr(str, flags->prec) - flags->prec;
    else
      str ? ft_putwstr(str) : ft_putstr("(null)");
  }
  else
  {
    if (flags->optdot && flags->prec)
      size += ft_putwnstr(str, flags->prec) - flags->prec;
    else
      str ? ft_putwstr(str) : ft_putstr("(null)");
    if (flags->min_size > size)
    {
      fill_it(flags, flags->min_size - size);
      size += flags->min_size - size;
    }

  }
  i[1] += size;
}

void	arg_is_wstr(t_flags *flags, va_list list, int *i)
{
  if (!(flags->optdot) || (flags->optdot && flags->prec) || flags->optsharp)
    print_wstr(flags, list, i);
  else if ((flags->optdot && (!(flags->prec)) && flags->min_size))
  {
    fill_it(flags, flags->min_size);
    i[1] += flags->min_size;
  }
}
