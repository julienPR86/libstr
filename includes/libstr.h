#ifndef LIBSTR_H
# define LIBSTR_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef enum e_STR_EXIT_STATUS
{
	STR_SUCCESS,
	STR_FAILURE,
}	STR_STATUS;

size_t	strLength(const char *s);

char	*strChar(const char *s, char c);

char	*strCopy(char *dst, const char *src);

char	*strnCopy(char *dst, const char *src, size_t n);

char	*strDup(const char *s);

char	*strnDup(const char *s, size_t n);

STR_STATUS	strAppend(char **dst, const char *src);

char	*strJoin(const char **src, const char *sep);

char	**strSplit(const char *src, const char *set);

#endif
