/*
	Do:
		#define LIBSTR_IMPLEMENTATION 
	to get access to the lib functions.
	This should be done only one time !
*/


#ifndef LIBSTR_H
# define LIBSTR_H

# include <stdlib.h>
# include <stdbool.h>

size_t	strLength(const char *s);

char	*strChar(const char *s, char c);

char	*strrChar(const char *s, char c);

int		strCompare(const char *s1, const char *s2);

int		strnCompare(const char *s1, const char *s2, size_t n);

char	*strCopy(char *dst, const char *src);

char	*strnCopy(char *dst, const char *src, size_t n);

char	*strDup(const char *s);

char	*strnDup(const char *s, size_t n);

char	*strAppend(char **dst, const char *src);

char	*strnAppend(char **dst, const char *src, size_t n);

char	*strJoin(const char **src, const char *sep);

char	**strSplit(const char *src, const char *set);

void	strDestroy(char **s);

# ifdef	LIBSTR_IMPLEMENTATION

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

char	*strrChar(const char *s, char c)
{
	char	*last = NULL;

	if (NULL == s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			last = (char *)s;
		++s;
	}
	if ('\0' == c)
		return ((char *)s);
	return (last);
}

int	strCompare(const char *s1, const char *s2)
{
	size_t	index = 0;

	if (NULL == s1 && NULL == s2)
		return (0);
	if (NULL == s1)
		return (-*s2);
	if (NULL == s2)
		return (*s1);
	while (*(s1 + index) && *(s2 + index))
		++index;
	return (*(s1 + index) - *(s2 + index));
}

int	strnCompare(const char *s1, const char *s2, size_t n)
{
	size_t	index = 0;

	if (NULL == s1 && NULL == s2)
		return (0);
	if (NULL == s1)
		return (-*s2);
	if (NULL == s2)
		return (*s1);
	while (*(s1 + index) && *(s2 + index) && index < n)
		++index;
	return (*(s1 + index) - *(s2 + index));
}

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

char	*strAppend(char **dst, const char *src)
{
	size_t	dst_size;
	size_t	src_size;
	char	*tmp;

	if (NULL == dst || NULL == src)
		return (NULL);
	dst_size = strLength(*dst);
	src_size = strLength(src);
	if (0 == src_size)
		return (*dst);
	tmp = malloc(sizeof(char) * (dst_size + src_size + 1));
	if (NULL == tmp)
		return (NULL);
	strCopy(tmp, *dst);
	strCopy(tmp + dst_size, src);
	free(*dst);
	*dst = tmp;
	return (*dst);
}

char	*strnAppend(char **dst, const char *src, size_t n)
{
	size_t	dst_size;
	size_t	src_size;
	char	*tmp;

	if (NULL == dst || NULL == src || 0 == n)
		return (NULL);
	dst_size = strLength(*dst);
	src_size = strLength(src);
	if (0 == src_size)
		return (*dst);
	if (n < src_size)
		src_size = n;
	tmp = malloc(sizeof(char) * (dst_size + src_size + 1));
	if (NULL == tmp)
		return (NULL);
	strCopy(tmp, *dst);
	strnCopy(tmp + dst_size, src, n);
	free(*dst);
	*dst = tmp;
	return (*dst);
}

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

static size_t	countWords(const char *str, const char *set)
{
	size_t	count;
	size_t	index;
	bool	is_word;

	if (NULL == str)
		return (0);
	is_word = 1;
	count = 0;
	index = 0;
	while (*(str + index))
	{
		if (strChar(set, *(str + index)))
			is_word = 1;
		else if (is_word)
		{
			count++;
			is_word = 0;
		}
		index++;
	}
	return (count);
}

char	**strSplit(const char *str, const char *set)
{
	char	**arr;
	size_t	wc;
	size_t	start_index;
	size_t	end_index;
	size_t	counter;

	if (NULL == str || NULL == set)
		return (NULL);
	wc = countWords(str, set);
	arr = (char **)malloc(sizeof(char *) * (wc + 1));
	if (NULL == arr)
		return (NULL);
	counter = 0;
	end_index = 0;
	while (counter < wc)
	{
		start_index = end_index;
		while (*(str + start_index) && strChar(set, *(str + start_index)))
			start_index++;
		end_index = start_index;
		while (*(str + end_index) && !strChar(set, *(str + end_index)))
			end_index++;
		*(arr + counter) = strnDup(str + start_index, end_index - start_index);
		if (NULL == *(arr + counter))
		{
			strDestroy(arr);
			return (NULL);
		}
		counter++;
	}
	*(arr + counter) = NULL;
	return (arr);
}

void	strDestroy(char **s)
{
	size_t	index;

	if (NULL == s)
		return ;
	index = 0;
	while (*(s + index))
	{
		free(*(s + index));
		*(s + index) = NULL;
		++index;
	}
	free(*(s + index));
	*(s + index) = NULL;
	free(s);
	return ;
}

# endif

#endif
