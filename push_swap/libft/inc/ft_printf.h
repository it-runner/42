#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	print_char(int c);
int	print_str(char *str);
int	print_ptr(void *ptr);
int	print_digit(int n);
int	print_unsigned(unsigned int n);
int	print_hex(unsigned int n, char format);

#endif