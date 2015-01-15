/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_o.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 11:16:08 by avallete          #+#    #+#             */
/*   Updated: 2015/01/15 18:23:34 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_linttoct(unsigned long long int nb, char *str)
{
  const int	mask2 = (7 << 0);
  int 		i;

  i = 1;
  if (nb > 0)
  {
    while ((nb >> (3 * i)) > 0)
      i++;
    while (nb > 0)
    {
      str[i - 1] = '0' + (nb & mask2);
      i--;
      nb >>= 3;
    }
  }
  else
    str[0] = '0';
}

void	print_octal(t_flags *flags, va_list list, int *i)
{
  unsigned long long int pt;
  char str[100];
  int  size;

  ft_bzero(str, 100);
  cast_octal(&pt, list, flags);
  size = 0;
  if (pt > 0 && flags->optsharp)
  {
    ft_putchar('0');
    size++;
  }
  if (pt < ULLONG_MAX)
  {
    ft_linttoct(pt, str);
    size += ft_strlen(str);
    if (flags->min_size > size + flags->prec)
      ft_filler(' ', flags->min_size - flags->prec);
    if (flags->prec)
    {
      ft_filler('0', flags->prec - size);
      size += flags->prec - size;
    }
    ft_putstr(str);
    if (flags->min_size > flags->prec + size)
      size += flags->min_size - size;
    i[1] += size;
  }
  else
  {
    size += 22;
    if (flags->min_size > size + flags->prec)
      ft_filler(' ', flags->min_size - flags->prec);
    if (flags->prec)
    {
      ft_filler('0', flags->prec - size);
      size += flags->prec - size;
    }
    ft_putstr("1777777777777777777777");
    if (flags->min_size > flags->prec + size)
      size += flags->min_size - size;
    i[1] += size;
  }
}

void  cast_octal(unsigned long long int *c, va_list list, t_flags *flags)
{
  if (flags->formf == 'h' && flags->formt == 'h' && flags->type != 'O')
    *c = (unsigned char)va_arg(list, int);
  else if (flags->formf == 'h')
    *c = (unsigned short)va_arg(list, int);
  else
    *c = va_arg(list, unsigned long long int);
}

void	arg_is_octal(t_flags *flags, va_list list, int *i)
{
  if ((!(flags->optdot)) || (flags->optdot && flags->prec) || flags->optsharp)
  {
    if (flags->type == 'o' || flags->type == 'O')
      print_octal(flags, list, i);
  }
}
