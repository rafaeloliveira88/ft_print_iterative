/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbraux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:17:43 by rafael            #+#    #+#             */
/*   Updated: 2024/11/20 12:57:37 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_getsize_i(long nbr, int base)
{
	int	count;

	count = 1;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	while (nbr >= base)
	{
		count++;
		nbr /= base;
	}
	return (count);
}

int	ft_getsize_ui(unsigned long nbr, int base)
{
	int	count;

	count = 1;
	while (nbr >= (unsigned long)base)
	{
		count++;
		nbr /= base;
	}
	return (count);
}

int	ft_putnbr_i(long nbr, int base, char *format_base)
{
	long	n;
	int		i;
	char	temp[21];
	int		size;

	ft_bzero(temp, 21);
	size = ft_getsize_i(nbr, base);
	n = nbr;
	i = size;
	if (n < 0)
		n = -n;
	while (--i >= 0)
	{
		temp[i] = format_base[n % base];
		n /= base;
	}
	if (nbr < 0)
		temp[0] = '-';
	i = 0;
	while (i < size)
		if (ft_putchar(temp[i++]) < 0)
			return (-1);
	return (size);
}

int	ft_putnbr_ui(unsigned int nbr, int base, char *format_base)
{
	unsigned int	n;
	int				i;
	char			temp[21];
	int				size;

	ft_bzero(temp, 21);
	size = ft_getsize_ui(nbr, base);
	n = nbr;
	i = size;
	while (--i >= 0)
	{
		temp[i] = format_base[n % base];
		n /= base;
	}
	i = 0;
	while (i < size)
		if (ft_putchar(temp[i++]) < 0)
			return (-1);
	return (size);
}

int	ft_putnbr_ul(unsigned long nbr, int base, char *format_base)
{
	unsigned long	n;
	int				i;
	char			temp[21];
	int				size;

	if (nbr == 0)
		return (ft_putstr ("(nil)"));
	ft_bzero(temp, 21);
	if (ft_putstr("0x") < 0)
		return (-1);
	size = ft_getsize_ui(nbr, base);
	n = nbr;
	i = size;
	while (--i >= 0)
	{
		temp[i] = format_base[n % base];
		n /= base;
	}
	i = 0;
	while (i < size)
		if (ft_putchar(temp[i++]) < 0)
			return (-1);
	return (size + 2);
}
