#include "ft_printf.h"

int    ft_print_str(va_list *ap, size_t *index_format)
{
    char	*s;

    s = va_arg(*ap, char *);
    *index_format = *index_format + 2;
    if (s == NULL)
    {
        return (ft_putstr("(null)"));
    }
    return (ft_putstr(s));
}

int    ft_print_char(va_list *ap, size_t *index_format)
{
    int c;

    c = (char)va_arg(*ap, int);
    ft_putchar(c);
    *index_format = *index_format + 2;
    return (1);
}