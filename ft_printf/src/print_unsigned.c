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
		n /= 10;
	}
	return (len);
}

static void	put_unsigned(unsigned int n)
{
	char	*symbols;

	symbols = "0123456789";
	if (n > 9)
		put_unsigned(n / 10);
	write(1, &symbols[n % 10], 1);
}

int	print_unsigned(unsigned int n)
{
	put_unsigned(n);
	return (calc_len(n));
}
