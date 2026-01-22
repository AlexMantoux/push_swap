/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:57:09 by amantoux          #+#    #+#             */
/*   Updated: 2026/01/22 13:50:04 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	format_d(int n, int fd);
int	format_f(double n, int fd);
int	format_u(unsigned int n, int fd);
int	format_x(unsigned long n, int fd);
int	format_x_upper(unsigned long n, int fd);
int	format_p(void *p, int fd);
int	format_c(char c, int fd);
int	format_s(char *str, int fd);
int	format_f(double f, int fd);
int	handle_format(const char *c, int i, va_list args, int fd);
int	ft_printf(int fd, const char *c, ...);

#endif