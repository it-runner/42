/*
	isalpha() checks for an alphabetic character; in the standard "C" locale,
	it is equivalent to (isupper(c) || islower(c)).
	In some locales, there may be additional characters for which
	isalpha() is true—letters which are neither uppercase nor lowercase.

	The value returned is nonzero if the character c falls into
	the tested class, and zero if not.
*/

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
