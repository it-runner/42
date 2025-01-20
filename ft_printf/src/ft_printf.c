/*
	printf() prints ARGUMENT(s) according to FORMAT.
*/

#include "ft_printf.h"

static int	print_format(const char specifier, va_list args)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len += print_char(va_arg(args, int));
	else if (specifier == 's')
		len += print_str(va_arg(args, char *));
	else if (specifier == 'p')
		len += print_ptr(va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		len += print_digit(va_arg(args, int));
	else if (specifier == 'u')
		len += print_unsigned(va_arg(args, unsigned int));
	else if (specifier == 'x')
		len += print_hex(va_arg(args, unsigned int), 'x');
	else if (specifier == 'X')
		len += print_hex(va_arg(args, unsigned int), 'X');
	else
		len += write(1, &specifier, 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start (args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += print_format(format[i + 1], args);
			i++;
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end (args);
	return (len);
}
