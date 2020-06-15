#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shopfunctions.h"

int compareAlpha(const void* a, const void* b)
{
	(void)a;
	(void)b;
	
	return 0;
}

int compareNum(const void* a, const void* b)
{
	(void)a;
	(void)b;
	
	return 0;
}

const Product* findProduct(const Product* p_array, const char* search_key, int (*cmp)(const void*, const void*))
{
	(void)p_array;
	(void)search_key;
	(void)cmp;
	
	return NULL;
}

