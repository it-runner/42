#include "ft_printf.h"

static size_t	calc_len(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static void	put_hex(unsigned int n, char format)
{
	char	*upper_digits;
	char	*lower_digits;

	upper_digits = "0123456789ABCDEF";
	lower_digits = "0123456789abcdef";
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	else if (n >= 16 && format == 'X')
		put_hex((n / 16), 'X');
	else if (n >= 16 && format == 'x')
		put_hex((n / 16), 'x');
	if (format == 'X')
		write(1, &upper_digits[n % 16], 1);
	else
		write(1, &lower_digits[n % 16], 1);
}

int	print_hex(unsigned int n, char format)
{
	put_hex(n, format);
	return (calc_len(n));
}
