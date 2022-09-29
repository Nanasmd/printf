/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:27:47 by nasamadi          #+#    #+#             */
/*   Updated: 2022/09/28 17:57:39 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

void	ft_putnbr_u(unsigned int n)
{
	unsigned long int	max_nb;

	max_nb = n;
	if (max_nb > 9)
		ft_putnbr_u(max_nb / 10);
	ft_putchar(max_nb % 10 + '0');
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

void	ft_putnbr_base(unsigned long int n, char *base)
{
	int	lenbase;

	lenbase = ft_strlen(base);
	if (n > (unsigned long int)lenbase - 1)
		ft_putnbr_base(n / lenbase, base);
	ft_putchar(base[n % lenbase]);
}

void	ft_putnbr_base_p(unsigned long int n, char *base)
{
	int	lenbase;

	lenbase = ft_strlen(base);
	if (n > (unsigned long int)lenbase - 1)
		ft_putnbr_base_p(n / lenbase, base);
	ft_putchar(base[n % lenbase]);
}
void	ft_check_percentage(va_list args, char s)
{
	if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(args, int));
	else if (s == 'c')
		ft_putchar(va_arg(args, int));
	else if (s == 's')
	{
		if (va_arg(args, char *) == NULL)
			ft_putstr("(null)");
		else
			ft_putstr(va_arg(args, char *));
	}
	else if (s == 'p')
	{
		if (va_arg(args, void *) == NULL)
			ft_putstr("(nil)");
		else
		{
			ft_putstr("0x");
			ft_putnbr_base_p(va_arg(args, unsigned long int), "0123456789abcdef");
		}
	}
	else if (s == 'u')
		ft_putnbr_u(va_arg(args, unsigned int));
	else if (s == 'x')
		ft_putnbr_base(va_arg(args, unsigned long int), "0123456789abcdef");
	else if (s == 'X')
		ft_putnbr_base(va_arg(args, unsigned long int), "0123456789ABCDEF");
	else if (s == '%')
		ft_putchar('%');
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int	i;
	
	i = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			ft_check_percentage(args, s[i]);
		}
		else
			ft_putchar(s[i]);
		i++;
	}
	va_end (args);
	return (0);
}
