/*
	isascii() checks whether c is a 7-bit unsigned char value
	that fits into the ASCII character set.

	The value returned is nonzero if the character c falls into
	the tested class, and zero if not.
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
