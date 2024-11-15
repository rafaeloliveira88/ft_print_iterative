/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:56:26 by rafael            #+#    #+#             */
/*   Updated: 2024/11/15 16:37:39 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long nbr, int base, int type)
{
	if (type == 'd' || type == 'i')
		return (ft_putaux(nbr, base, "0123456789"));
	else if (type == 'u')
		return (ft_putauxu(nbr, base, "0123456789"));
	else if (type == 'x')
		return (ft_putauxu(nbr, base, "0123456789abcdef"));
	else if (type == 'X')
		return (ft_putauxu(nbr, base, "0123456789ABCDEF"));
	else if (type == 'p')
		return (ft_putauxptr(nbr, base, "0123456789abcdef"));
	return (-1);
}
