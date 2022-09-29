/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:03:49 by nasamadi          #+#    #+#             */
/*   Updated: 2022/09/29 18:12:23 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"printf.h"

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

void	ft_check_s(va_list args, char s)
{
	if (s == 's')
	{
		if (va_arg(args, char *) == NULL)
			ft_putstr("(null)");
		else
			ft_putstr(va_arg(args, char *));
	}
}
