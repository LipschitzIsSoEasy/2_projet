/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:24:33 by mtian             #+#    #+#             */
/*   Updated: 2024/06/10 18:27:00 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_condition(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base [i] == '-'
			|| (base[i] >= 9 && base [i] <= 13) || base[i] == 32)
		{
			return (0);
		}
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(unsigned long long l, char *base, size_t *count)
{
	size_t	len;

	if (ft_condition(base) == 0)
	{
		return ;
	}
	len = ft_strlen(base);
	if (l % len != l)
	{
		ft_putnbr_base(l / len, base, count);
	}
	ft_putchar(base[l % len]);
	*count = *count + 1;
}

void	ft_putnbr(int nb, size_t *count)
{
	long	l;

	l = nb;
	if (l < 0)
	{
		l = -l;
		ft_putchar('-');
		*count = *count + 1;
	}
	if (l % 10 != l)
	{
		ft_putnbr(l / 10, count);
	}
	ft_putchar(l % 10 + '0');
	*count = *count + 1;
}

void	ft_putnbr_unsigned_int(unsigned int l, size_t *count)
{
	if (l % 10 != l)
	{
		ft_putnbr(l / 10, count);
	}
	ft_putchar(l % 10 + '0');
	*count = *count + 1;
}
