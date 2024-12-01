/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:24:15 by aelbour           #+#    #+#             */
/*   Updated: 2024/12/01 17:47:42 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> 
# include <unistd.h> 

int		ft_printf(const char *s, ...);
void	ft_putchar(int c);
void	ft_putstr(char *s, int *j);
size_t	ft_strlen(const char *s);
void	ft_putnbr(int n, int *j);
void	ft_put_unsigned(unsigned int n, int *j);
void	ft_put_hexa(size_t i, int upr, int mem, int *p);

#endif
