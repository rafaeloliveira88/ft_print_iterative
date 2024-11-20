/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:37:00 by rafael            #+#    #+#             */
/*   Updated: 2024/11/20 12:58:57 by rjose-ma         ###   ########.fr       */
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
	else if(type == '\0')
		return (1);
	return (-1);
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
		if (*f == '%' && *(f+1)){
			result = ft_process_variables(*(++f), list);
		}
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

#include "ft_printf.h"
int main()
{
	ft_printf("%s", NULL);
	printf("%s", NULL);

	ft_printf("%");
	printf("%");
}
