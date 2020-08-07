#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shopfunctions.h"

int compareAlpha(const void* a, const void* b)
{
	const Product *prod_a = a;
	const Product *prod_b = b;

	int res = strcmp(prod_a->name, prod_b->name);
	
	return res;
}

int compareNum(const void* a, const void* b)
{
	const Product *prod_a = a;
	const Product *prod_b = b;

	// b is larger than a, thus return 1
	if (prod_b->in_stock > prod_a->in_stock) {  
		return 1;
	} else if (prod_b->in_stock < prod_a->in_stock) {
		return -1;
	} else {
		// It the 2 values are the same, compare names
		return compareAlpha(a, b);
	}
	
	return 0;
}

const Product* findProduct(const Product* p_array, const char* search_key, int (*cmp)(const void*, const void*))
{
	unsigned int i = 0;
	const Product *ptr_product = p_array;

	while (ptr_product[i].name[0] != 0) i++;

	return bsearch(search_key, ptr_product, i, sizeof(Product), cmp);
}