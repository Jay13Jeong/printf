#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		cnt;

	cnt = 0;
	if (n < 0)
	{
		cnt += write(1, "-", 1);
		if (n == (1 << 31))
		{
			cnt += ft_putnbr(-(n / 10));
			return (cnt + write(1, "8", 1));
		}
		n *= -1;
	}
	if (n >= 10)
		cnt += ft_putnbr(n / 10);
	return (cnt + write(1, &"0123456789"[n % 10], 1));
}

int	ft_x_putnbr(unsigned long long n, unsigned long long base, char *list)
{
	int		cnt;
	int		i;
	char	temp[99];

	i = 0;
	cnt = 0;
	while (1)
	{
		temp[i++] = list[n % base];
		n /= base;
		if (n == 0)
			break ;
	}
	while (i--)
		cnt += write(1, &temp[i], 1);
	return (cnt);
}

int	flag_print(va_list va, const char form)
{
	int		cnt;

	cnt = 0;
	if (form == 'c')
		cnt += ft_putchar(va_arg(va, int));
	else if (form == 's')
		cnt += ft_putstr(va_arg(va, char *));
	else if (form == 'p')
	{
		cnt += write(1, "0x", 2);
		cnt += ft_x_putnbr(va_arg(va, unsigned long long), \
				 16, "0123456789abcdef");
	}
	else if (form == 'd' || form == 'i')
		cnt += ft_putnbr(va_arg(va, int));
	else if (form == 'u')
		cnt += ft_x_putnbr(va_arg(va, unsigned int), 10, "0123456789");
	else if (form == 'x')
		cnt += ft_x_putnbr(va_arg(va, unsigned int), 16, "0123456789abcdef");
	else if (form == 'X')
		cnt += ft_x_putnbr(va_arg(va, unsigned int), 16, "0123456789ABCDEF");
	else if (form == '%')
		cnt += write(1, "%", 1);
	return (cnt);
}

int	check_type(char a)
{
	int		i;
	char	*index;

	index = "cspdiuxX%";
	i = -1;
	while (++i < 9)
	{
		if (index[i] == a)
			return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		cnt;
	va_list	va;

	va_start(va, format);
	i = -1;
	cnt = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (check_type(format[i + 1]))
				cnt += flag_print(va, ((char *)format)[++i]);
		}
		else
			cnt += write(1, &format[i], 1);
	}
	va_end(va);
	return (cnt);
}
