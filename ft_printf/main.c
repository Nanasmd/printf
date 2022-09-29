/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:38:19 by nasamadi          #+#    #+#             */
/*   Updated: 2022/09/29 17:39:19 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"printf.h"

int	main()
{
	int	a;
	int	*b;

	char	c;
	char	*d;

	char	e;
	char	*f;

	a = 0;
	b = &a;
	c = '0';
	d = &c;
	e = 'A';
	f = &e;
	ft_printf("%p  %d\n", NULL, *b);
	ft_printf("%p %d\n", d, *d);
	ft_printf("%p %d\n\n", f, *f);
	ft_printf("%s\n\n", NULL);
	ft_printf("%d %i\n", 0, 0);
	ft_printf("%d %d\n", 214748367, INT_MAX);
	ft_printf("%d %d\n\n", -2147483648, INT_MIN);
	ft_printf("%u %u\n\n", 0xffffffff, UINT_MAX);
	printf("%p %d\n", NULL, *b);
	printf("%p %d\n", d, *d);
	printf("%p %d\n\n", f, *f);
	//printf("%s\n\n", NULL);
	printf("%d %i\n", 0, 0);
	printf("%d %d\n", 214748367, INT_MAX);
	printf("%d %d\n\n", -214748368, INT_MIN);
	printf("%u %u\n\n", 0xffffffff, UINT_MAX);
	return (0);
}
