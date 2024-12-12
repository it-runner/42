/* 
	tolower() converts uppercase letters to lowerrcase.

	The value returned is that of the converted letter,
	or c if the conversion was not possible.
*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}
