/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:05:36 by nasamadi          #+#    #+#             */
/*   Updated: 2022/09/29 18:09:54 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"print.h"

void	ft_putnbr_base(unsigned long int n, char *base)
{
	int	lenbase;

	lenbase = ft_strlen(base);
	if (n > (unsigned long int)lenbase - 1)
		ft_putnbr_base(n / lenbase, base);
	ft_putchar(base[n % lenbase]);
}

void	ft_check_x(va_list args, char s)
{
	if (s == 'x')
		ft_putnbr_base(va_arg(args, unsigned long int), "0123456789abcdef");
}

