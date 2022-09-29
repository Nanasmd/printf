/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:03:20 by nasamadi          #+#    #+#             */
/*   Updated: 2022/09/29 18:12:46 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_check_c(va_list args, char s)
{
	if (s == 'c')
		ft_putchar(va_arg(args, int));
}

