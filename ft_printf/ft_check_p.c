/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:04:10 by nasamadi          #+#    #+#             */
/*   Updated: 2022/09/29 18:11:48 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<printf.h>

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putnbr_p(unsigned long int n, char *base)
{
	int	lenbase;

	lenbase = ft_strlen(base);
	if (n > (unsigned long int)lenbase - 1)
		ft_putnbr_base_p(n / lenbase, base);
	ft_putchar(base[n % lenbase]);
}


void	ft_check_p(va_list args, char s)
{
	if (s == 'p')
	{
		if (va_arg(args, void *) == NULL)
			ft_putstr("(nil)");
		else
		{
			ft_putstr("0x");
			ft_putnbr_p(va_arg(args, unsigned long int), "0123456789abcdef");
		}
	}
}

