/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:24:15 by aelbour           #+#    #+#             */
/*   Updated: 2024/11/30 18:32:58 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h> 
# include <libc.h> 

int		ft_printf(const char *, ...);
void	ft_putchar(int);
void	ft_putstr(char *, int *);
size_t	ft_strlen(const char *, int *);
void	ft_putnbr(int, int *);
void	ft_put_unsigned(unsigned int, int *);
void	ft_put_hexa(size_t n, int upr, int mem, int *);

# endif
