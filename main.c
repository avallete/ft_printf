/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:29:05 by avallete          #+#    #+#             */
/*   Updated: 2015/01/11 11:08:26 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_printf.h>
# include <stdio.h>

int main(void)
{
	int ret1;
	int ret2;

	ret1 = printf("pjolie test %%%%%s%c%c\n", "un foutu Test\n", 'l', 'w');
	ret2 = ft_printf("fjolie test %%%%%s%c%c\n", "un foutu Test\n", 'l', 'w');
	ft_putnbr(ret1);
	ft_putnbr(ret2);
	return (0);
}
