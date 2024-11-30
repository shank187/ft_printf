/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:39:46 by aelbour           #+#    #+#             */
/*   Updated: 2024/11/30 18:33:22 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s, int *j)
{
	if (s)
	{
		write(1, s, ft_strlen(s));
		*j += (ft_strlen(s) - 1);
	}
	else
	{
		write(1, "(null)", 6);
		*j += 5;
	}
}

void	ft_putnbr(int n, int *j)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		(*j)++;
		ft_putnbr(n / 10, j);
	}
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void	ft_put_unsigned(unsigned int n, int *j)
{
	char	c;

	if (n >= 10)
	{
		(*j)++;
		ft_put_unsigned(n / 10, j);
	}
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void	ft_put_hexa(size_t i, int upr, int mem, int *p)
{
	size_t	j;
	char s[20];

	j = 0;
	if(!mem)
		i = (unsigned int)i;
	while(1)
	{
		if (upr && !mem)
			s[j++] = "0123456789ABCDEF"[i % 16];
		else
			s[j++] = "0123456789abcdef"[i % 16];
		i/=16;
		if(!i)
			break;
	}
	*p += ((int)j + 2);
	if(mem)
		write(1, "0x", 2);
	while(j > 0)
	{
		--j;
		write(1,&s[j], 1);
	}
}
