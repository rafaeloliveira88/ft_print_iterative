/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:45:36 by rafael            #+#    #+#             */
/*   Updated: 2024/11/15 15:14:00 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(long nbr, int base, int type);
int		ft_getsize(long nbr, int base);
int		ft_getsizeu(unsigned long nbr, int base);
int		ft_putaux(long nbr, int base, char *format_base);
int		ft_putauxu(unsigned int nbr, int base, char *format_base);
int		ft_putauxptr(unsigned long nbr, int base, char *format_base);
void	ft_bzero(char *array, int n);