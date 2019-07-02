#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

vector* vector_init(int capacity)
{
	vector* v = malloc(sizeof(vector));
	if (v == NULL) {
		free(v);
		puts("Cant initialize pointer");
		return NULL;
	}
	v->capacity = capacity;
	v->total = 0;
	v->items = malloc(sizeof(void*) * v->capacity);
	return v;
}

int vector_total(vector* v)
{
	return v->total;
}

static void vector_resize(vector* v, int capacity)
{
	void** items = realloc(v->items, sizeof(void*) * capacity);
	if (items) {
		v->items = items;
		v->capacity = capacity;
	}
}

void vector_add(vector* v, void* item)
{
	if (v->capacity == v->total)
		vector_resize(v, v->capacity * 2);
	v->items[v->total++] = item;
}

void vector_set(vector* v, int index, void* item)
{
	if (index >= 0 && index < v->total)
		v->items[index] = item;
}

void* vector_get(vector* v, int index)
{
	if (index >= 0 && index < v->total)
		return v->items[index];
	return NULL;
}

void vector_delete(vector* v, int index)
{
	if (index >= v->total||index < 0) {
		return;
	}

	v->items[index] = NULL;

	int i, j;
	void** newarr = (void**)malloc(sizeof(void*) * v->capacity);

	if (newarr == NULL) {
		free(newarr);
		puts("Cannot initialize array");
		exit(1);
	}

	for (i = 0, j = 0; i < v->total; i++) {
		if (v->items[i] != NULL) {
			newarr[j] = v->items[i];
			j++;
		}
	}

	vector_free(v->items);

	v->items = newarr;
	v->total--;
}

void vector_free(vector * v)
{
	free(v->items);
}

void** get_items(vector* v) {
	return v->items;
}
