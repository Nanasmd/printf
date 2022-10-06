/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:27:47 by nasamadi          #+#    #+#             */
/*   Updated: 2022/10/05 15:00:10 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"printf.h"

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
	}
	if (max_nb > 9)
		i = ft_putnbr(max_nb / 10, i++);
	ft_putchar(max_nb % 10 + '0');
	return (i);
}

int	ft_putnbr_u(unsigned int n, int i)
{
	unsigned long int	max_nb;

	max_nb = n;
	if (max_nb > 9)
		i = ft_putnbr_u(max_nb / 10, i++);
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
		i = ft_putnbr_base(n / lenbase, base, i + 1);
	ft_putchar(base[n % lenbase]);
	return (i);
}

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
		char				*oui;

		oui = va_arg(args, char *);
		if (oui == NULL)
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
		i = ft_putnbr_base(va_arg(args, unsigned long int), "0123456789abcdef", 1);
	else if (s == 'X')
		i = ft_putnbr_base(va_arg(args, unsigned long int), "0123456789ABCDEF", 1);
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
	char a;

	a = '0';

	printf("  %d\n\n", ft_printf("%x/%X %s la note de ma nan%c :%d", 256, 256, "cest", 'a', 3));
	printf("  %d\n", printf("%x/%X %s la note de ma nan%c :%d", 256, 256, "cest", 'a', 3));
	printf("%d", ft_printf("%s", "damdam zizi"));
	ft_printf("ft : %X\n", 125698);
	printf("%X\n\n", 125698);
	ft_printf("ft : %p\n", &a);
	printf("%p\n", &a);
	/*ft_printf("%p %d\n", d, *d);
	ft_printf("%p %d\n\n", f, *f);
	ft_printf("%s\n\n", NULL);
	ft_printf("%d %i\n", 0, 0);
	ft_printf("%d %d\n", 2147483647, INT_MAX);
	ft_printf("%ld %d\n\n", -2147483647, INT_MIN);
	ft_printf("%u %u\n\n", 0xffffffff, UINT_MAX);
	printf("%p %d\n", b, *b);
	printf("%p %d\n", d, *d);
	printf("%p %d\n\n", f, *f);
	printf("%s\n\n", NULL);
	printf("%d %i\n", 0, 0);
	printf("%d %d\n", 2147483647, INT_MAX);
	printf("%ld %d\n\n", -2147483648, INT_MIN);
	printf("%u %u\n\n", 0xffffffff, UINT_MAX);*/
	
	return (0);
}
