#include "ft_printf.h"

size_t ft_putchar(char c)
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