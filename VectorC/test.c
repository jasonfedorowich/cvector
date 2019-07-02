#include <stdio.h>
#include "vector.h"
#include "spaceship.h"

int main() {
	vector* v = vector_init(10);
	vector_add(v, "test");
	vector_add(v, "test2");

	char* test =(char *)vector_get(v, 0);
	puts(test);
	vector_delete(v, 0);
	char* test2 = (char*)vector_get(v, 0);
	puts(test2);

	vector* v1 = vector_init(10);
	Spaceship* s = createship();
	Spaceship* s1 = createship();
	
	vector_add(v1, s);
	vector_add(v1, s1);

	Spaceship* testship=(Spaceship*)vector_get(v1, 0);
	printf("%f\n", testship->sx);

	vector_delete(v1, 0);
	Spaceship* testship2 = (Spaceship*)vector_get(v1, 0);
	ship_accelerate(testship2);
	ship_position(testship2);
	printf("%f\n", testship2->sy);

}