/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:29:05 by avallete          #+#    #+#             */
/*   Updated: 2015/01/10 16:30:14 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_printf.h>
# include <stdio.h>

int main(void)
{
	int ret1;
	int ret2;

	ret1 = printf("jolie test %21.10d\n", 3);
	ret1 = ft_printf("jolie test %21.10d\n", 3);
	//	printf("%d -- %d\n", ret1, ret2);
	return (0);
}
