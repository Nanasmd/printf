/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:09:59 by nasamadi          #+#    #+#             */
/*   Updated: 2022/10/07 15:11:14 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n, int i)
{
	long int	max_nb;

	max_nb = n;
	if (max_nb < 0)
	{
		ft_putchar('-');
		max_nb *= -1;
		i++;
	}
	if (max_nb > 9)
		i = ft_putnbr(max_nb / 10, ++i);
	ft_putchar(max_nb % 10 + '0');
	return (i);
}

int	ft_putnbr_u(unsigned int n, int i)
{
	unsigned long int	max_nb;

	max_nb = n;
	if (max_nb > 9)
		i = ft_putnbr_u(max_nb / 10, ++i);
	ft_putchar(max_nb % 10 + '0');
	return (i);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putnbr_base(unsigned long int n, char *base, int i)
{
	int	lenbase;

	lenbase = ft_strlen(base);
	if (n > (unsigned long int)lenbase - 1)
		i = ft_putnbr_base(n / lenbase, base, ++i);
	ft_putchar(base[n % lenbase]);
	return (i);
}

int	ft_putnbr_base_p(unsigned long int n, char *base, int i)
{
	int	lenbase;

	lenbase = ft_strlen(base);
	if (n > (unsigned long int)lenbase - 1)
		i = ft_putnbr_base_p(n / lenbase, base, ++i);
	ft_putchar(base[n % lenbase]);
	return (i);
}
