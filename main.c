/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:29:05 by avallete          #+#    #+#             */
/*   Updated: 2015/01/10 19:25:59 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_printf.h>
# include <stdio.h>

int main(void)
{
	int ret1;
	int ret2;

	ret1 = printf("jolie test %%%%%ls%s\n", L"trop", NULL);
	ret1 = ft_printf("jolie test %%%%%ls%s\n", "trop", NULL);
	//	printf("%d -- %d\n", ret1, ret2);
	return (0);
}
