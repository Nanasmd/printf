/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:04:41 by nasamadi          #+#    #+#             */
/*   Updated: 2022/09/29 18:10:56 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"printf.h"

void	ft_putnbr(int n)
{
	long int	max_nb;

	max_nb = n;
	if (max_nb < 0)
	{
		ft_putchar('-');
		max_nb *= -1;
	}
	if (max_nb > 9)
		ft_putnbr(max_nb / 10);
	ft_putchar(max_nb % 10 + '0');
}

void	ft_check_di(va_list args, char s)
{
	if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(args, int));
}
