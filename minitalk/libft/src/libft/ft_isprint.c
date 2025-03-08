/*
	isprint() checks for any printable character
	including space (ASCII 32 - 126).

	The value returned is nonzero if the character c falls into
	the tested class, and zero if not.
*/

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
