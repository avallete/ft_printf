/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 10:19:59 by avallete          #+#    #+#             */
/*   Updated: 2015/01/10 16:48:16 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <libft.h>
# include <stdarg.h>

typedef	struct	s_flags
{
	char		optmin;
	char		optplus;
	char		optzero;
	char		optsharp;
	char		optspace;
	char		formf;
	char		formt;
	int			min_size;
	int			prec;
	int			size;
	char		type;
}				t_flags;



/*
** ----------
** Misc functions
** ----------
*/

int		check_exstr(const char *str);
char	*ft_grep_first_number(char *str, int *i);
int		type_cmp(char c);

/*
** ----------
** Check_flags functions
** Functions assign value in t_flags with boolean value for each option.
** ----------
*/

void	check_flg(char *str, t_flags *flags, int *i);
void	check_width(char *str, t_flags *flags, int *i);
void	check_prec(char *str, t_flags *flags, int *i);
void	check_form(char *str, t_flags *flags, int *i);
void	check_type(char *str, t_flags *flags, int *i);


/*
** ----------
** Ft_argument functions
** Functions call check_flags and convert function for each argument.
** ----------
*/

int		found_flags(const char *str, va_list list);
void	ft_arg_sort(const char *str, va_list list, int *i);
void	init_flags(char *str, t_flags *flags, int *i);



/*
** ----------
** Converter function
** ----------
*/

/* Modulo function */
int arg_is_mod(t_flags *flags, va_list list, int *i);

/* String function */
int arg_is_string(t_flags *flags, va_list list, int *i);

/*
** ----------
** Ft_printf function
** The main function, check if str exist, launch args sort if % found.
** Else function do putstr and return (strlen)
** ----------
*/

int ft_printf(const char *format, ...);
#endif
