/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:13:21 by mtian             #+#    #+#             */
/*   Updated: 2024/06/10 19:24:15 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h> 

/* ft_printf_base.c */
size_t		ft_putchar(char c);
size_t		ft_strlen(char *base);
size_t		ft_putstr(char *s);

/* ft_printf_convert.c */
int			ft_condition(char	*base);
void		ft_putnbr_base(unsigned long long l, char *base, size_t *count);
void		ft_putnbr(int nb, size_t *count);
void		ft_putnbr_unsigned_int(unsigned int l, size_t *count);

/* ft_printf_print_sc.c */
int			ft_print_str(va_list *ap, size_t *index_format);
int			ft_print_char(va_list *ap, size_t *index_format);

/* ft_printf_print_iuxxp.c */
int			ft_print_int(va_list *ap, size_t *index_format);
int			ft_print_unsigned_int(va_list *ap, size_t *index_format);
int			ft_print_hexa_lower(va_list *ap, size_t *index_format);
int			ft_print_hexa_upper(va_list *ap, size_t *index_format);
int			ft_print_pointer(va_list *ap, size_t *index_format);

/* ft_printf.c */
int			is_format(char c);
int			process_format(const char *list_format, va_list *ap, size_t *i);
int			ft_printf(const char *list_format, ...);

#endif
