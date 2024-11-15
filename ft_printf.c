/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:37:00 by rafael            #+#    #+#             */
/*   Updated: 2024/11/15 12:55:30 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_process_variables(char type, va_list args)
{
	if (type == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (type == 'p')
		return (ft_putnbr(va_arg(args, unsigned long), 16, 'p'));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(args, int), 10, 'd'));
	else if (type == 'u')
		return (ft_putnbr(va_arg(args, unsigned int), 10, 'u'));
	else if (type == 'x')
		return (ft_putnbr(va_arg(args, unsigned int), 16, 'x'));
	else if (type == 'X')
		return (ft_putnbr(va_arg(args, unsigned int), 16, 'X'));
	else if (type == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *f, ...)
{
	va_list	list;
	int		count;
	int		result;

	count = 0;
	va_start(list, f);
	if (!f)
		return (-1);
	while (*f)
	{
		if (*f == '%')
			result = ft_process_variables(*(++f), list);
		else
			result = ft_putchar(*f);
		if (result < 0)
		{
			va_end(list);
			return (-1);
		}
		count += result;
		f++;
	}
	va_end(list);
	return (count);
}
