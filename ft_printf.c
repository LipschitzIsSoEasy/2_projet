/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:02:01 by mtian             #+#    #+#             */
/*   Updated: 2024/06/10 19:12:45 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_format(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X')
	{
		return (1);
	}
	return (0);
}

int	process_format(const char *list_format, va_list *ap, size_t *i)
{
	size_t	count;

	count = 0;
	if (list_format[*i + 1] == 's')
		count = ft_print_str(ap, i);
	else if (list_format[*i + 1] == 'd' || list_format[*i + 1] == 'i')
		count = ft_print_int(ap, i);
	else if (list_format[*i + 1] == 'c')
		count = ft_print_char(ap, i);
	else if (list_format[*i + 1] == 'x')
		count = ft_print_hexa_lower(ap, i);
	else if (list_format[*i + 1] == 'X')
		count = ft_print_hexa_upper(ap, i);
	else if (list_format[*i + 1] == 'u')
		count = ft_print_unsigned_int(ap, i);
	else if (list_format[*i + 1] == 'p')
		count = ft_print_pointer(ap, i);
	else if (list_format[*i + 1] == '%')
	{
		count = count + ft_putchar('%');
		*i = *i + 2;
	}
	else if (!is_format(list_format[*i + 1]))
		*i = *i + 1;
	return (count);
}

int	ft_printf(const char *list_format, ...)
{
	va_list	ap;
	size_t	i;
	size_t	count;

	if (list_format == NULL)
		return (-1);
	i = 0;
	count = 0;
	va_start(ap, list_format);
	while (*(list_format + i) != '\0')
	{
		if (list_format[i] != '%')
		{
			ft_putchar(list_format[i]);
			count++;
			i++;
		}
		else
			count += process_format(list_format, &ap, &i);
	}
	va_end(ap);
	return (count);
}
// for test: p

// #include <stdio.h>
// int main(void) {
//     //printf("%p\n", 0);
//     printf("fff:%d\n", ft_printf("%p\n", 0));
//     printf("ppp:%d\n", printf("%p\n", 0));
//     //printf(NULL);
//     //ft_printf(NULL);
//     return (0);
// }

// // for test: x  unsigned int
// #include <stdio.h>
// int main(void) {
//     printf("%x\n", -1);
//     ft_printf("%x\n", -1);
//     return (0);
// }
/*
#include <stdio.h>
int main(void)
{
    // ft_printf("aa%s\n", "eee");
    // printf("aa%s\n", "eee");
    // ft_print("aa%d%%%%a%scc%se\n%ce\n%u", -4577, "bbb", "ddd", 'O', -12);
    // printf("\n===========================\n");
    // printf("aa%d%%%%a%scc%se\n%ce\n%u", -4577, "bbb", "ddd", 'O', -12);

    // ft_print("aa%de\n%u==", -4577,  -12);
    // printf("\n===========================\n");
    // printf("aa%de\n%u==\n", -4577, -12);

    // ft_print("aa%de\n%i==", -4577,  012);
    // printf("\n===========================\n");
    // printf("aa%de\n%i==\n", -4577, 012);

    // fft_print("%%%%EE");
    // printf("\n===========================\n");
    // printf("%%%%EE");

    // ft_printf("%x\n%X\n%x", 216666, -216, -456);
    // printf("\n===========================\n");
    // printf("%x\n%X\n%x", 216666, -216, -456);

    // ft_printf("%u\n", 0);
    // printf("\n===========================\n");
    // printf("%u\n", 0);

    // char    r;
    // char    *rrr = "3erezrer";

    // r = 'r';
    // ft_printf("ft_printf-rrr:%p\n", &rrr);
    // printf("\n===========================\n");
    // printf("printf-rrr:%p\n", &rrr);

    // ft_printf("ft_printf-r:%p\n", &r);
    // printf("\n===========================\n");
    // printf("printf-r:%p\n", &r);

    // char r1, r2, r3;
    // ft_printf("ft_printf-1:%p\n", &r1);
    // printf("p-1:%p\n", &r1);
    // printf("===========================\n");
    // ft_printf("ft_printf-2:%p\n", &r2);
    // printf("p-2:%p\n", &r2);
    // printf("===========================\n");
    // ft_printf("ft_printf-3:%p\n", &r3);
    // printf("p-3:%p\n", &r3);
    // printf("===========================\n");

    // ft_printf("%%%m%m\n%");
    // printf("aaa%%%m%m\n%");

    // ft_printf("%d\n", 0013332);
    // printf("%i\n", 0013332);
    // printf("%d\n", 012);
    // printf("%i\n", 012);

    // ft_printf("%%m%m\n%");
    // printf("%%m%m\n%");

    // printf("ft_printf:%d\n",ft_printf("%%m%m\n%"));
    // printf("printf:%d\n", printf("%%m%m\n%"));

    // printf("ft_printf:%d\n",ft_printf("aa%d%%%%a%scc%se\n%ce\n%u",
    // -4577, "bbb", "ddd", 'O', -12));
    // printf("printf:%d\n", printf("aa%d%%%%a%scc%se\n%ce\n%u",
    // -4577, "bbb", "ddd", 'O', -12));


    // printf("ft_printf:%d\n",ft_printf("%c", 0));
    // printf("printf:%d\n", printf("%c", 0));

    // printf("ft_printf:%d\n",ft_printf("%s", NULL));
    // printf("printf:%d\n", printf("%s", NULL));
    
    // printf("ft_printf:%d\n",ft_printf("%d", -2147482637));
    // printf("printf:%d\n", printf("%d", -2147482637));
    return (0);
}
*/
