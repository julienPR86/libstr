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

/**
 * @brief Returns the length of @a s.
 */
size_t	strLength(const char *s);

/**
 * @brief Returns a pointer to the first occurrence of @a c in @a s.
 * @return A pointer to the occurrence, or NULL if @a c is not found.
 */
char	*strFindChar(const char *s, char c);

/**
 * @brief Returns a pointer to the last occurrence of @a c in @a s.
 * @return A pointer to the occurrence, or NULL if @a c is not found.
 */
char	*strFindCharRev(const char *s, char c);

/**
 * @brief Returns a pointer to the first occurrence of any character from @a set in @a s.
 * @return A pointer to the occurrence, or NULL if no character is found.
 */
char	*strFindChars(const char *s, const char *set);

/**
 * @brief Returns a pointer to the last occurrence of any character from @a set in @a s.
 * @return A pointer to the occurrence, or NULL if no character is found.
 */
char	*strFindCharsRev(const char *s, const char *set);

/**
 * @brief Returns a pointer to the first occurrence of the substring @a needle in @a s.
 * @return A pointer to the occurrence, or NULL if @a needle is not found.
 */
char	*strFind(const char *s, const char *needle);

/**
 * @brief Returns a pointer to the first occurrence of the substring @a needle within the first @a n characters of @a s.
 * @return A pointer to the occurrence, or NULL if @a needle is not found.
 */
char	*strFindN(const char *s, const char *needle, size_t n);

/**
 * @brief Compares the two strings @a s1 and @a s2.
 * @return A negative value if @a s1 is less than @a s2, a positive value if @a s1 is greater than @a s2, or 0 if they are equal.
 */
int	strCompare(const char *s1, const char *s2);

/**
 * @brief Compares at most the first @a n characters of @a s1 and @a s2.
 * @return A negative value if @a s1 is less than @a s2, a positive value if @a s1 is greater than @a s2, or 0 if they are equal.
 */
int	strCompareN(const char *s1, const char *s2, size_t n);

/**
 * @brief Copies @a src into @a dst.
 * @warning @a dst must be large enough to hold @a src and its null terminator.
 * @return @a dst on success, or NULL on failure.
 */
char	*strCopy(char *dst, const char *src);

/**
 * @brief Copies at most the first @a n characters of @a src into @a dst.
 * @warning @a dst must be large enough to hold the copied characters and the null terminator.
 * @return @a dst on success, or NULL on failure.
 */
char	*strCopyN(char *dst, const char *src, size_t n);

/**
 * @brief Concatenates @a src to the end of @a dst.
 * @warning @a dst must be null-terminated and large enough to hold the result.
 * @return @a dst on success, or NULL on failure.
 */
char	*strConcat(char *dst, const char *src);

/**
 * @brief Concatenates at most the first @a n characters of @a src to @a dst.
 * @warning @a dst must be null-terminated and large enough to hold the result.
 * @return @a dst on success, or NULL on failure.
 */
char	*strConcatN(char *dst, const char *src, size_t n);

/**
 * @brief Returns an allocated copy of @a s.
 * @return A pointer to the allocated string, or NULL on failure.
 */
char	*strDup(const char *s);

/**
 * @brief Returns an allocated copy of the first @a n characters of @a s.
 * @return A pointer to the allocated string, or NULL on failure.
 */
char	*strDupN(const char *s, size_t n);

/**
 * @brief Appends @a src to the end of @a dst.
 * @param dst A pointer to the allocated string to modify.
 * @return A pointer to the resulting string, or NULL on failure.
 */
char	*strAppend(char **dst, const char *src);

/**
 * @brief Appends at most the first @a n characters of @a src to @a dst.
 * @param dst A pointer to the allocated string to modify.
 * @return A pointer to the resulting string, or NULL on failure.
 */
char	*strAppendN(char **dst, const char *src, size_t n);

/**
 * @brief Joins all strings in @a src, using @a sep as a separator.
 * @param src An array of strings.
 * @param sep The separator to insert between strings.
 * @warning @a src must end with a NULL pointer to indicate the end of the array.
 * @return The allocated joined string, or NULL on failure.
 */
char	*strJoin(const char *const *src, const char *sep);

/**
 * @brief Splits @a src whenever a character from @a set is found.
 * @return An allocated array of strings, or NULL on failure.
 */
char	**strSplit(const char *src, const char *set);

/**
 * @brief Removes leading characters from @a s that belong to @a set.
 * @return The allocated trimmed string, or NULL on failure.
 */
char	*strTrimLeft(const char *s, const char *set);

/**
 * @brief Removes trailing characters from @a s that belong to @a set.
 * @return The allocated trimmed string, or NULL on failure.
 */
char	*strTrimRight(const char *s, const char *set);

/**
 * @brief Returns the substring of @a s from @a start to @a end, inclusive.
 * @return The allocated substring, or NULL on failure.
 */
char	*strSub(const char *s, size_t start, size_t end);

/**
 * @brief Returns the number of words in @a s.
 *
 * A word is separated by one or more characters from @a set.
 */
size_t	strCountWords(const char *s, const char *set);

/**
 * @brief Frees an array of strings.
 * @warning @a s must end with a NULL pointer to indicate the end of the array.
 */
void	strDestroy(char **strs);

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

char	*strFindChar(const char *s, char c)
{
	if (NULL == s)
		return (NULL);
	while (*s && *s != c)
		++s;
	if ('\0' == *s && '\0' != c)
		return (NULL);
	return ((char *)s);
}

char	*strFindCharRev(const char *s, char c)
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

char	*strFindChars(const char *s, const char *set)
{
	if (NULL == s || NULL == set)
		return (NULL);
	while (*s)
	{
		if (strFindChar(set, *s))
			break;
		++s;
	}
	if ('\0' == *s)
		return (NULL);
	return ((char *)s);
}

char	*strFindCharsRev(const char *s, const char *set)
{
	char	*last = NULL;

	if (NULL == s)
		return (NULL);
	while (*s)
	{
		if (strFindChar(set, *s))
			last = (char *)s;
		++s;
	}
	return (last);
}

char	*strFind(const char *s, const char *needle)
{
	size_t	needle_size;
	char	*occ;

	if (NULL == s || NULL == needle)
		return (NULL);
	needle_size = strLength(needle);
	occ = strFindChar(s, *needle);
	while (occ)
	{
		if (0 == strCompareN(occ, needle, needle_size))
			return (occ);
		occ = strFindChar(occ + 1, *needle);
	}
	return (NULL);
}

char	*strFindN(const char *s, const char *needle, size_t n)
{
	size_t	needle_size;
	char	*occ;

	if (NULL == s || NULL == needle || 0 == n)
		return (NULL);
	needle_size = strLength(needle);
	occ = strFindChar(s, *needle);
	while (occ)
	{
		if (0 == strCompareN(occ, needle, needle_size))
			return (occ);
		occ = strFindChar(occ + 1, *needle);
		if (occ - s + needle_size > n)
			return (NULL);
	}
	return (NULL);
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
	while (*(s1 + index) && *(s2 + index) && *(s1 + index) == *(s2 + index))
		++index;
	return (*(s1 + index) - *(s2 + index));
}

int	strCompareN(const char *s1, const char *s2, size_t n)
{
	size_t	index = 0;

	if (NULL == s1 && NULL == s2)
		return (0);
	if (NULL == s1)
		return (-*s2);
	if (NULL == s2)
		return (*s1);
	while (*(s1 + index) && *(s2 + index) && *(s1 + index) == *(s2 + index) && index < n - 1)
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

char	*strCopyN(char *dst, const char *src, size_t n)
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

char	*strConcat(char *dst, const char *src)
{
	size_t	end;

	if (NULL == dst)
		return (NULL);
	if (NULL == src)
		return (dst);
	end = strLength(dst);
	strCopy(dst + end, src);
	return (dst);
}

char	*strConcatN(char *dst, const char *src, size_t n)
{
	size_t	end;

	if (NULL == dst)
		return (NULL);
	if (NULL == src || 0 == n)
		return (dst);
	end = strLength(dst);
	strCopyN(dst + end, src, n);
	return (dst);
}

char	*strDup(const char *s)
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

char	*strDupN(const char *s, size_t n)
{
	size_t	size;
	char	*dup;

	if (NULL == s)
		return (NULL);
	size = strLength(s);
	dup = malloc(sizeof(char) * (size + 1));
	if (NULL == dup)
		return (NULL);
	strCopyN(dup, s, n);
	return (dup);
}

char	*strAppend(char **dst, const char *src)
{
	size_t	dst_size;
	size_t	src_size;
	char	*concat;

	if (NULL == dst)
		return (NULL);
	if (NULL == src)
		return (*dst);
	if (NULL == *dst)
	{
		*dst = strDup(src);
		return (*dst);
	}
	dst_size = strLength(*dst);
	src_size = strLength(src);
	if (0 == src_size)
		return ((char *)(*dst));
	concat = malloc(sizeof(char) * (dst_size + src_size + 1));
	if (NULL == concat)
		return (NULL);
	strCopy(concat, *dst);
	strConcat(concat, src);
	free(*dst);
	*dst = concat;
	return (*dst);
}

char	*strAppendN(char **dst, const char *src, size_t n)
{
	size_t	dst_size;
	size_t	src_size;
	char	*concat;

	if (NULL == dst)
		return (NULL);
	if (NULL == src || 0 == n)
		return (*dst);
	if (NULL == *dst)
	{
		*dst = strDup(src);
		return (*dst);
	}
	dst_size = strLength(*dst);
	src_size = strLength(src);
	if (0 == src_size)
		return ((char *)(*dst));
	concat = malloc(sizeof(char) * (dst_size + src_size + 1));
	if (NULL == concat)
		return (NULL);
	strCopy(concat, *dst);
	strConcatN(concat, src, n);
	free(*dst);
	*dst = concat;
	return (*dst);
}

char	*strJoin(const char *const *s, const char *sep)
{
	size_t	index = 0;
	char	*join = NULL;
	char	*tmp;

	if (NULL == s || NULL == *s)
		return (NULL);
	while (*(s + index))
	{
		tmp = strAppend(&join, *(s + index));
		if (NULL == tmp)
		{
			free(join);
			return (NULL);
		}
		join = tmp;
		if (*(s + index + 1))
		{
			tmp = strAppend(&join, sep);
			if (NULL == tmp)
			{
				free(join);
				return (NULL);
			}
			join = tmp;
		}
		++index;
	}
	return (join);
}

size_t	strCountWords(const char *s, const char *set)
{
	size_t	count = 0;
	bool	is_word;

	if (NULL == s || NULL == set)
		return (0);
	is_word = 1;
	while (*s)
	{
		if (strFindChar(set, *s))
			is_word = 1;
		else if (is_word)
		{
			count++;
			is_word = 0;
		}
		++s;
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
	wc = strCountWords(str, set);
	arr = (char **)malloc(sizeof(char *) * (wc + 1));
	if (NULL == arr)
		return (NULL);
	counter = 0;
	end_index = 0;
	while (counter < wc)
	{
		start_index = end_index;
		while (*(str + start_index) && strFindChar(set, *(str + start_index)))
			start_index++;
		end_index = start_index;
		while (*(str + end_index) && !strFindChar(set, *(str + end_index)))
			end_index++;
		*(arr + counter) = strDupN(str + start_index, end_index - start_index);
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

char	*strTrimLeft(const char *s, const char *set)
{
	char	*trimmed;

	if (NULL == s || NULL == set)
		return (NULL);
	while (*s)
	{
		if (strFindChar(set, *s))
			break;
		++s;
	}
	if ('\0' == *s)
		return (strDup(s));
	trimmed = strDup(s + 1);
	if (NULL == trimmed)
		return (NULL);
	return (trimmed);
}

char	*strTrimRight(const char *s, const char *set)
{
	size_t	index = 0;
	size_t	last = 0;
	char	*trimmed;

	if (NULL == s || NULL == set)
		return (NULL);
	while (*(s + index))
	{
		if (strFindChar(set, *(s + index)))
			last = index;
		++index;
	}
	if (0 == last && NULL == strFindChar(set, *s))
		return (strDup(s));
	trimmed = strDupN(s, last);
	if (NULL == trimmed)
		return (NULL);
	return (trimmed);
}

char	*strSub(const char *s, size_t start, size_t end)
{
	const size_t	slen = strLength(s);
	char			*sub;

	if (NULL == s || start > slen || start > end)
		return (NULL);
	sub = malloc(((end < slen ? end : slen) - start + 2) * sizeof(char));
	if (NULL == sub)
		return (NULL);
	strCopyN(sub, s + start, end - start + 1);
	return (sub);
}

void	strDestroy(char **strs)
{
	size_t	index;

	if (NULL == strs)
		return ;
	index = 0;
	while (*(strs + index))
	{
		free(*(strs + index));
		*(strs + index) = NULL;
		++index;
	}
	free(*(strs + index));
	*(strs + index) = NULL;
	free(strs);
	return ;
}

# endif

#endif
