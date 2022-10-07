/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:29:43 by nasamadi          #+#    #+#             */
/*   Updated: 2022/10/07 15:10:18 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int	ft_check_percentage(va_list args, char s);
int	ft_printf(const char *s, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n, int i);
int	ft_putnbr_u(unsigned int n, int i);
int	ft_strlen(char *s);
int	ft_putnbr_base(unsigned long int n, char *base, int i);
int	ft_putnbr_base_p(unsigned long int n, char *base, int i);

#endif
