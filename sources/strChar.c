#include "libstr.h"

char *strChar(const char *s, char c)
{
	if (NULL == s)
		return (NULL);
	while (*s && *s != c)
		++s;
	if ('\0' == *s && '\0' != c)
		return (NULL);
	return ((char *)s);
}
