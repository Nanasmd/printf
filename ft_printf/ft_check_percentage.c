/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_percentage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:07:31 by nasamadi          #+#    #+#             */
/*   Updated: 2022/09/29 18:08:57 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_check_percentage(va_list args, char s)
{
	if (s == '%')
		ft_putchar('%');
}
