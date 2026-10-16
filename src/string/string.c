// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	char *d = destination;
	while (*source != '\0') {
		*d = *source;
		d++;
		source++;
	}
	*d = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	char *d = destination;
	while (len && *source != '\0') {
		*d = *source;
		d++;
		source++;
		len--;
	}
	while (len--) {
		*d = '\0';
		d++;
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	int i = 0;
	while (destination[i] != '\0')
		i++;
	strcpy(destination + i, source);
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	int i = 0;
	while (destination[i] != '\0')
		i++;
	strncpy(destination + i, source, len);
	destination[len + i] = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	char *s1 = (char *)str1;
	char *s2 = (char *)str2;
	while (*s1 == *s2) {
		if (*s1 == '\0')
			return 0;
		s1++;
		s2++;
	}
	if (*s1 < *s2)
		return -1;
	else
		return 1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	char *s1 = (char *)str1;
	char *s2 = (char *)str2;
	while (len != 0 && *s1 == *s2) {
		if (*s1 == '\0')
			return 0;
		s1++;
		s2++;
		len--;
	}
	if (len == 0)
		return 0;
	if (*s1 < *s2)
		return -1;
	else
		return 1;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	char *s = (char *)str;
	while (*s != '\0') {
		if (*s == (char)c)
			return s;
		s++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	char *s = (char *)str;
	char *found = NULL;
	while (*s != '\0') {
		if (*s == (char)c)
			found = s;
		s++;
	}
	return found;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	char *copy = (char *)haystack;
	int len = strlen(needle);
	while (*copy != '\0') {
		if (strncmp(copy, needle, len) == 0)
			return copy;
		copy++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	char *copy = (char *)haystack;
	int len = strlen(needle);
	char *found = NULL;
	while (*copy != '\0') {
		if (strncmp(copy, needle, len) == 0)
			found = copy;
		copy++;
	}
	return found;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *dest = (char *)destination;
	char *src = (char *)source;
	for (size_t i = 0; i < num; i++)
		dest[i] = src[i];
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *dest = (char *)destination;
	char *src = (char *)source;
	if (dest < src) {
		for (size_t i = 0; i < num; i++)
			dest[i] = src[i];
	} else if (dest > src) {
		for (size_t i = num; i != 0; i--)
			dest[i - 1] = src[i - 1];
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const unsigned char *p1 = (const unsigned char *)ptr1;
	const unsigned char *p2 = (const unsigned char *)ptr2;
	for (size_t i = 0; i < num; i++) {
		if (p1[i] != p2[i]) {
			if (p1[i] < p2[i])
				return -1;
			else
				return 1;
		}
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	unsigned char *src = (unsigned char *)source;
	for (size_t i = 0; i < num; i++)
		src[i] = (unsigned char)value;
	return source;
}
