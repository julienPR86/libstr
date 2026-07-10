#include "libstr.h"

char	*strCopy(char *dst, const char *src)
{
	size_t	index;

	if (NULL == dst || NULL == src)
		return (NULL);
	index = 0;
	while (*(src + index))
	{
		*(dst + index) = *(src + index);
		++index;
	}
	*(dst + index) = *(src + index);
	return (dst);
}

char	*strnCopy(char *dst, const char *src, size_t n)
{
	size_t	index;

	if (NULL == dst || NULL == src)
		return (NULL);
	index = 0;
	while (*(src + index) && index < n)
	{
		*(dst + index) = *(src + index);
		++index;
	}
	*(dst + index) = '\0';
	return (dst);
}
