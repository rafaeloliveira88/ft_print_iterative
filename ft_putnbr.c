/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:56:26 by rafael            #+#    #+#             */
/*   Updated: 2024/11/20 12:57:24 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long nbr, int base, int type)
{
	if (type == 'd' || type == 'i')
		return (ft_putnbr_i(nbr, base, "0123456789"));
	else if (type == 'u')
		return (ft_putnbr_ui(nbr, base, "0123456789"));
	else if (type == 'x')
		return (ft_putnbr_ui(nbr, base, "0123456789abcdef"));
	else if (type == 'X')
		return (ft_putnbr_ui(nbr, base, "0123456789ABCDEF"));
	else if (type == 'p')
		return (ft_putnbr_ul(nbr, base, "0123456789abcdef"));
	return (1);
}
