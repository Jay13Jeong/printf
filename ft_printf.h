#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int				ft_putchar(char c);
int				ft_putstr(char *s);
int				ft_printf(const char *format, ...);
#endif