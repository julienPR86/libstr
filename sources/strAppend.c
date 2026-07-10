#include "libstr.h"

STR_STATUS	strAppend(char **dst, const char *src)
{
	size_t	dst_size;
	size_t	src_size;
	char	*tmp;

	if (NULL == dst || NULL == src)
		return (STR_SUCCESS);
	dst_size = strLength(*dst);
	src_size = strLength(src);
	if (0 == src_size)
		return (STR_SUCCESS);
	tmp = malloc(sizeof(char) * (dst_size + src_size + 1));
	if (NULL == tmp)
		return (STR_FAILURE);
	strCopy(tmp, *dst);
	strCopy(tmp + dst_size, src);
	free(*dst);
	*dst = tmp;
	return (STR_SUCCESS);
}
