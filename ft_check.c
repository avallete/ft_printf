/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:10:19 by avallete          #+#    #+#             */
/*   Updated: 2015/01/10 16:12:59 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_printf.h>


void	check_flg(char *str, t_flags *flags, int *i)
{
	while (str[*i] == '#' || str[*i] == '+' || str[*i] == '0' || \
			str[*i] == '-' || str[*i] == ' ')
	{
		str[*i] == '#' ? (flags->optsharp = 1) : (flags->optsharp += 0);
		str[*i] == '-' ? (flags->optmin = 1) : (flags->optmin += 0);
		str[*i] == '+' ? (flags->optplus = 1) : (flags->optplus += 0);
		str[*i] == '0' ? (flags->optzero = 1) : (flags->optzero += 0);
		str[*i] == ' ' ? (flags->optspace = 1) : (flags->optspace += 0);
		i[0] += 1;
	}
}

void	check_width(char *str, t_flags *flags, int *i)
{
	char *nmb;

	nmb = ft_grep_first_number(str, i);
	flags->min_size = ft_atoi(nmb);
}

void	check_prec(char *str, t_flags *flags, int *i)
{
	char *pres;

	if (str[i[0]] == '.')
	{
		*i += 1;
		pres = ft_grep_first_number(str, i);
		flags->prec = ft_atoi(pres);
	}
}

void	check_form(char *str, t_flags *flags, int *i)
{
	if (str[i[0]] == 'h' || str[i[0]] == 'l' || str[i[0]] == 'j' || str[i[0]] == 'z')
	{
		flags->formf = str[i[0]];
		i[0] += 1;
		if (str[i[0]] == 'h' || str[i[0]] == 'l')
		{
			flags->formt = str[i[0]];
			str[i[0]] += 1;
		}
		else
			flags->formt = '\0';
	}
	else
		flags->formf = '\0';
}

void	check_type(char *str, t_flags *flags, int *i)
{
	if (type_cmp(str[i[0]]))
	{
		flags->type = str[i[0]];
		i[0] += 1;
	}
	else
		flags->type = '\0';
}


