/*
	isdigit() checks for a digit (0 through 9 / ASCII 48 - 57).

	The value returned is nonzero if the character c falls into
	the tested class, and zero if not.
*/

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
