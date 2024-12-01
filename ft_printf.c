/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:21:54 by aelbour           #+#    #+#             */
/*   Updated: 2024/12/01 21:55:08 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	handle_conversions(const char *s, size_t *i, int *j, va_list args)
{
	int	k;

	k = 0;
	if (s[(*i) + 1] == 'c')
		ft_putchar(va_arg(args, int));
	else if (s[(*i) + 1] == 's')
		ft_putstr(va_arg(args, char *), j);
	else if (s[(*i) + 1] == '%')
		write(1, "%%", 1);
	else if (s[(*i) + 1] == 'd')
		ft_putnbr(va_arg(args, int), j);
	else if (s[(*i) + 1] == 'i')
		ft_putnbr(va_arg(args, int), j);
	else if (s[(*i) + 1] == 'u')
		ft_put_unsigned(va_arg(args, unsigned int), j);
	else if (s[(*i) + 1] == 'x')
		ft_put_hexa(va_arg(args, unsigned int), 0, 0, j);
	else if (s[(*i) + 1] == 'X')
		ft_put_hexa(va_arg(args, unsigned int), 1, 0, j);
	else if (s[(*i) + 1] == 'p')
		ft_put_hexa((size_t) va_arg(args, void *), 1, 1, j);
	else
		k = -1;
	*(i) += (1 + k);
	*(j) += (1 + k);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	i;
	int		j;

	if (write(1, 0, 0) < 0)
		return (-1);
	va_start(args, s);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == '%')
			handle_conversions(s, &i, &j, args);
		else
		{
			ft_putchar(s[i]);
			j++;
		}
		i++;
	}
	va_end(args);
	return (j);
}
