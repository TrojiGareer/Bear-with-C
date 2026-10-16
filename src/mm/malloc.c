// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	if (size == 0) {
		return NULL;
	}
	void *p = mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (p == MAP_FAILED) {
		return NULL;
	}
	mem_list_add(p, size);
	return p;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	if (nmemb == 0 || size == 0) {
		return NULL;
	}
	if (nmemb * size > (size_t)-1) {
		return NULL;
	}
	void *p = malloc(nmemb * size);
	if (p != NULL) {
		memset(p, 0, nmemb * size);
	}
	return p;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr == NULL) {
		return;
	}
	struct mem_list *node = mem_list_find(ptr);
	if (node == NULL) {
		return;
	}
	munmap(ptr, node->len);
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	// if (ptr == NULL) {
	// 	return malloc(size);
	// }
	// if (size == 0) {
	// 	free(ptr);
	// 	return NULL;
	// }
	struct mem_list *node = mem_list_find(ptr);
	if (node == NULL) {
		return NULL;
	}
	if (size <= node->len) {
		return ptr;
	}
	void *new_ptr = malloc(size);
	if (new_ptr == NULL) {
		return NULL;
	}
	memcpy(new_ptr, ptr, node->len);
	free(ptr);
	return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	// if (ptr == NULL) {
	// 	return calloc(nmemb, size);
	// }
	// if (size == 0) {
	// 	free(ptr);
	// 	return NULL;
	// }
	struct mem_list *node = mem_list_find(ptr);
	// if (node == NULL) {
	// 	return NULL;
	// }
	// if (nmemb * size > (size_t)-1) {
	// 	return NULL;
	// }
	// if (nmemb * size <= node->len) {
	// 	return ptr;
	// }
	void *new_ptr = calloc(nmemb, size);
	// if (new_ptr == NULL) {
	// 	return NULL;
	// }
	memcpy(new_ptr, ptr, node->len);
	free(ptr);
	return new_ptr;
}
