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
/*void	ft_putnbr_base_cap(unsigned long int n, int base)
{
	//if (base < 2)
		//return (NULL);
	if (n <= 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= (unsigned long int)base)
		ft_putnbr_base_cap(n / base, base);
	if ((n % 16) <= 9)
		ft_putchar(n % 16 + 48);
	else if (n % 16 >= 10)
		ft_putchar(n % 16 + 55);
}

void	ft_putnbr_base_low(unsigned long int n, int base)
{
	//if (base < 2)
		//return (NULL);
	if (n <= 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= (unsigned long int)base)
		ft_putnbr_base_low(n / base, base);
	if ((n % 16) <= 9)
		ft_putchar(n % 16 + 48);
	else if (n % 16 >= 10)
		ft_putchar(n % 16 + 87);
}*/

void	ft_check_percentage(va_list args, char s)
{
	if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(args, int));
	else if (s == 'c')
		ft_putchar(va_arg(args, int));
	else if (s == 's')
		ft_putstr(va_arg(args, char *));
	/*else if (s == 'p')
	
	else if (s == 'u')
		
	else if (s == 'x')
		ft_putnbr_base_low(va_arg(args, unsigned long int));
	else if (s == 'X')
		ft_putnbr_base_cap(va_arg(args, unsigned long int));*/
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
}
int	main()
{
	ft_printf("%x  %d\n", 123, 23);
	printf("%X %d", 123, 23);
	return (0);
}
