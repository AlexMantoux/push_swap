/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantoux <amantoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:57:09 by amantoux          #+#    #+#             */
/*   Updated: 2025/11/13 09:11:50 by amantoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	format_d(int n);
int	format_u(unsigned int n);
int	format_x(unsigned long n);
int	format_x_upper(unsigned long n);
int	format_p(void *p);
int	format_c(char c);
int	format_s(char *str);
int	handle_format(const char *c, int i, va_list args);
int	ft_printf(const char *c, ...);

#endif