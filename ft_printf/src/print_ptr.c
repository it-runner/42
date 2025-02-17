#include "ft_printf.h"

static size_t	len_ptr(unsigned long long ptr)
{
	size_t	len;

	len = 0;
	if (ptr == 0)
		return (1);
	while (ptr)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

static void	put_ptr(unsigned long long ptr)
{
	char	*symbols;

	symbols = "0123456789abcdef";
	if (ptr >= 16)
		put_ptr (ptr / 16);
	write(1, &symbols[ptr % 16], 1);
}

int	print_ptr(void *ptr)
{
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	put_ptr((unsigned long long)ptr);
	return (len_ptr((unsigned long long)ptr) + 2);
}
