#include "libstr.h"

char *strDup(const char *s)
{
	size_t	size;
	char	*dup;

	if (NULL == s)
		return (NULL);
	size = strLength(s);
	dup = malloc(sizeof(char) * (size + 1));
	if (NULL == dup)
		return (NULL);
	strCopy(dup, s);
	return (dup);
}

char *strnDup(const char *s, size_t n)
{
	size_t	size;
	char	*dup;

	if (NULL == s)
		return (NULL);
	size = strLength(s);
	dup = malloc(sizeof(char) * (size + 1));
	if (NULL == dup)
		return (NULL);
	strnCopy(dup, s, n);
	return (dup);
}
