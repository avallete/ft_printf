/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 10:19:59 by avallete          #+#    #+#             */
/*   Updated: 2015/01/12 17:13:38 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <libft.h>
# include <stdarg.h>
# define HEXMAJ ("0123456789ABCDEF")
# define HEXMIN ("0123456789abcdef")
# define OXMAJ	("0X000000000000")
# define OXMIN	("0x000000000000")

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
char	*ft_grep_first_number(const char *str, int *i, char *result);
int		type_cmp(const char c);

/*
** ----------
** Check_flags functions
** Functions assign value in t_flags with boolean value for each option.
** ----------
*/

void	check_flg(const char *str, t_flags *flags, int *i);
void	check_width(const char *str, t_flags *flags, int *i);
void	check_prec(const char *str, t_flags *flags, int *i);
void	check_form(const char *str, t_flags *flags, int *i);
void	check_type(const char *str, t_flags *flags, int *i);


/*
** ----------
** Ft_argument functions
** Functions call check_flags and convert function for each argument.
** ----------
*/

int		found_flags(const char *str, va_list list);
void	ft_arg_sort(const char *str, va_list list, int *i);
void	init_flags(const char *str, t_flags *flags, int *i);



/*
** ----------
** Converter function
** ----------
*/

/* Modulo function */
void	arg_is_mod(t_flags *flags, int *i);

/* String function */
void	arg_is_string(t_flags *flags, va_list list, int *i);
void	print_string(va_list list, int *i);

/* Char function */
void	arg_is_char(t_flags *flags, va_list list, int *i);
void	print_char(va_list list, int *i);

/* Int function */
void	arg_is_int(t_flags *flags, va_list list, int *i);
void	print_int(t_flags *flags, va_list list, int *i);
int		print_int_fill(t_flags *flags, int *i, int c);
void	print_int_opt(t_flags *flags, int c, int size, int *i);
void	print_plus(t_flags *flags, int *i, int c);
void	fill_it(t_flags *flags, int size);
/*Long Int function */
void	arg_is_longi(t_flags *flags, va_list list, int *i);
void	print_longi(t_flags *flags, va_list list, int *i);
int		print_lint_fill(t_flags *flags, int *i, long int l);
void	print_longint_opt(t_flags *flags, long int l, int size, int *i);
int		ft_longnbrlen(long int nb);
void	ft_putlongnbr(long int nb);
/* Ptr function */
void	ft_longinttohexa(unsigned long int nb, char *str, char *hex);
void	arg_is_ptr(t_flags *flags, va_list list, int *i);
void	print_ptr(va_list list, int *i);

/*
** ----------
** Ft_printf function
** The main function, check if str exist, launch args sort if % found.
** Else function do putstr and return (strlen)
** ----------
*/

int ft_printf(const char *format, ...);
#endif
