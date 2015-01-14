/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 14:49:51 by avallete          #+#    #+#             */
/*   Updated: 2015/01/14 19:14:20 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_linttohexa(unsigned long int nb, char *str, char *hex)
{
  int e;

  e = 1;
  if (nb > 0)
  {
    while ((nb >> 4 * e) > 0)
      e++;
    while (nb > 0)
    {
      str[e-- + 1] = hex[(nb & 0xF)];
      nb >>= 4;
    }
  }
  else
    str[2] = '0';
}

void	print_ptr(t_flags *flags, va_list list, int *i)
{
  unsigned long int pt;
  char str[] = OXMIN;
  int               size;

  ft_bzero(str + 2, 12);
  pt = va_arg(list, unsigned long int);
  ft_linttohexa(pt, str, HEXMIN);
  size = ft_strlen(str);
  flags->min_size - size > 0 ? \
  (fill_it(flags, flags->min_size - size), i[1] += flags->min_size - size) :
  (size += 0);
  ft_putstr(str);
  i[1] += ft_strlen(str);
}

void	print_rev_ptr(t_flags *flags, va_list list, int *i)
{
  unsigned long int pt;
  char str[] = OXMIN;
  int               size;

  ft_bzero(str + 2, 12);
  pt = va_arg(list, unsigned long int);
  ft_linttohexa(pt, str, HEXMIN);
  size = ft_strlen(str);
  ft_putstr(str);
  flags->min_size - size > 0 ? \
  (fill_it(flags, flags->min_size - size), i[1] += flags->min_size - size) :
  (size += 0);
  i[1] += ft_strlen(str);
}

void	arg_is_ptr(t_flags *flags, va_list list, int *i)
{
  if (flags->optmin || flags->optzero)
    print_rev_ptr(flags, list, i);
  else
    print_ptr(flags, list, i);
}
