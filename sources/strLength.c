#include "libstr.h"

size_t	strLength(const char *s)
{
	size_t	size;

	if (NULL == s)
		return (0);
	size = 0;
	while (*(s + size))
		++size;
	return (size);
}
