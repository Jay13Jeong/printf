#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int				cnt;
	unsigned char	*s2;

	if (s == 0)
		return (write(1, "(null)", 6));
	cnt = 0;
	s2 = (unsigned char *)s;
	while (*s2)
		cnt += write(1, (s2++), 1);
	return (cnt);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
