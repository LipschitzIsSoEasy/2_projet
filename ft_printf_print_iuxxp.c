/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   222ft_printf_print_iuxxp.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:38:55 by mtian             #+#    #+#             */
/*   Updated: 2024/06/10 19:00:01 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(va_list *ap, size_t *index_format)
{
	int		d;
	size_t	count;

	count = 0;
	d = va_arg(*ap, int);
	ft_putnbr(d, &count);
	*index_format = *index_format + 2;
	return (count);
}

int	ft_print_unsigned_int(va_list *ap, size_t *index_format)
{
	unsigned int	unsigned_i;
	size_t			count;

	count = 0;
	unsigned_i = va_arg(*ap, unsigned int);
	ft_putnbr_unsigned_int(unsigned_i, &count);
	*index_format = *index_format + 2;
	return (count);
}

int	ft_print_hexa_lower(va_list *ap, size_t *index_format)
{
	unsigned int	x;
	size_t			count;

	count = 0;
	x = va_arg(*ap, unsigned int);
	ft_putnbr_base(x, "0123456789abcdef", &count);
	*index_format = *index_format + 2;
	return (count);
}

int	ft_print_hexa_upper(va_list *ap, size_t *index_format)
{
	unsigned int	x;
	size_t			count;

	count = 0;
	x = va_arg(*ap, unsigned int);
	ft_putnbr_base(x, "0123456789ABCDEF", &count);
	*index_format = *index_format + 2;
	return (count);
}

int	ft_print_pointer(va_list *ap, size_t *index_format)
{
	char		*p;
	size_t		count;

	count = 0;
	p = va_arg(*ap, char *);
	*index_format = *index_format + 2;
	if (p == NULL)
	{
		return (ft_putstr("(nil)"));
	}
	ft_putstr("0x");
	ft_putnbr_base((unsigned long long)&p[0], "0123456789abcdef", &count);
	count = count + 2;
	return (count);
}
