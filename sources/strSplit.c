#include "libstr.h"

static void strDestroy(char **s)
{
	size_t	index;

	if (NULL == s)
		return ;
	index = 0;
	while (*(s + index))
	{
		free(*(s + index));
		++index;
	}
	free(*(s + index));
	free(s);
	return ;
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
