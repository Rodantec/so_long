/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:37:26 by rodantec          #+#    #+#             */
/*   Updated: 2024/11/12 12:20:46 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_percent(void);
int		ft_hexamin(int n);
int		ft_hexamaj(int n);
int		ft_iitoa(int n);
int		ft_unsignedi(unsigned int n);
int		ft_size_n_hexa(long n);
int		ft_size_n_deci(long n);
int		ft_printstr_fd(char *s, int fd);
int		ft_printchar_fd(char c, int fd);
int		ft_voidpointer(void *ptr);

#endif