#include "libstr.h"

char	*strJoin(const char **s, const char *sep)
{
	size_t	index;
	char	*join;

	if (NULL == s || NULL == *s || NULL == sep)
		return (NULL);
	join = NULL;
	index = 0;
	while (*(s + index))
	{
		strAppend(&join, *(s + index));
		if (*(s + index + 1))
			strAppend(&join, sep);
		++index;
	}
	return (join);
}
