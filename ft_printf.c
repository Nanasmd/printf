/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:27:47 by nasamadi          #+#    #+#             */
/*   Updated: 2022/10/07 15:12:04 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_check_percentage(va_list args, char s)
{
	int	i;

	i = 0;
	if (s == 'd' || s == 'i')
		i = ft_putnbr(va_arg(args, int), 1);
	else if (s == 'c')
		i = ft_putchar(va_arg(args, int));
	else if (s == 's')
	{
		char	*oui;

		oui = va_arg(args, char *);
		if (!oui)
			i = ft_putstr("(null)");
		else
			i = ft_putstr(oui);
	}
	else if (s == 'p')
	{
		unsigned long int	oui;

		oui = va_arg(args, unsigned long int);
		if (!oui)
			i = ft_putstr("(nil)");
		else
		{
			i += ft_putstr("0x");
			i += ft_putnbr_base_p(oui, "0123456789abcdef", 1);
		}
	}
	else if (s == 'u')
		i = ft_putnbr_u(va_arg(args, unsigned int), 1);
	else if (s == 'x')
		i = ft_putnbr_base(va_arg(args, unsigned long int),
				"0123456789abcdef", 1);
	else if (s == 'X')
		i = ft_putnbr_base(va_arg(args, unsigned long int),
				"0123456789ABCDEF", 1);
	else if (s == '%')
		i = ft_putchar('%');
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		len;
	
	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			len += ft_check_percentage(args, s[i]);
		}
		else
		{
			ft_putchar(s[i]);
			len++;
		}
		i++;
	}
	va_end (args);
	return (len);
}

int	main(void)
{
	printf("{%d}\n", printf("pr :%lx", LONG_MAX));
	printf("{%d}", ft_printf("ft :%x", LONG_MAX));
}
