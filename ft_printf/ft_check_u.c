/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:05:12 by nasamadi          #+#    #+#             */
/*   Updated: 2022/09/29 18:10:24 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"printf.h"

void	ft_putnbr_u(unsigned int n)
{
	unsigned long int	max_nb;

	max_nb = n;
	if (max_nb > 9)
		ft_putnbr_u(max_nb / 10);
	ft_putchar(max_nb % 10 + '0');
}

void	ft_check_u(va_list args, char s)
{
	if (s == 'u')
		ft_putnbr_u(va_arg(args, unsigned int));
}

