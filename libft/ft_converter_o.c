/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_o.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 11:16:08 by avallete          #+#    #+#             */
/*   Updated: 2015/01/15 10:52:00 by avallete         ###   ########.fr       */
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

  ft_bzero(str, 100);
  cast_octal(&pt, list, flags);
  if (pt > 0 && flags->optsharp)
  {
    ft_putchar('0');
    i[1]++;
  }
  if (pt < ULLONG_MAX)
  {

    ft_linttoct(pt, str);
    ft_putstr(str);
    i[1] += ft_strlen(str);
  }
  else
  {
    ft_putstr("1777777777777777777777");
    i[1] += 22;
  }
}

void  cast_octal(unsigned long long int *c, va_list list, t_flags *flags)
{
  if (flags->formf == 'h' && flags->formt == 'h')
    *c = (unsigned char)va_arg(list, int);
  else if (flags->formf == 'h' && flags->formt == '\0')
    *c = (unsigned short)va_arg(list, int);
  else
    *c = va_arg(list, unsigned long long int);
}

void	arg_is_octal(t_flags *flags, va_list list, int *i)
{
  if (flags->type == 'o' || flags->type == 'O')
    print_octal(flags, list, i);
}
