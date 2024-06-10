/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:16:20 by mtian             #+#    #+#             */
/*   Updated: 2024/06/10 18:24:13 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t	ft_strlen(char *base)
{
	size_t	i;

	i = 0;
	while (base[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}
