#include "spaceship.h"
#include <stdio.h>

#include <math.h>
Spaceship* createship()
{
	Spaceship* s = malloc(sizeof(Spaceship));

	if (s == NULL) {
		free(s);
		puts("Cant initialize pointer");
		return NULL;
	}
	//s->gone = 1;
	s->speed = 0.0;
	s->heading = 0.0; // radians
	s->sx = 10.0;
	s->sy = 10.0;
	return s;
}


void destroy_ship(Spaceship* s) {
	free(s);
}

//key event space bar
void ship_accelerate(Spaceship* s)
{
	if (s->speed < MAX_SPEED) {

		s->speed += ACCELERATE_SHIP;
	}
	if (s->speed > MAX_SPEED) {

		s->speed = MAX_SPEED;

	}
	return;

}

//key event back
void ship_decelerate(Spaceship* s) {
	if (s->speed > 0) {
		s->speed -= DECELERATE_SHIP;
	}
	else if (s->speed < 0) {
		s->speed = 0;
	}
	return;

}

void ship_position(Spaceship* s) {
	//calculate the geometrical changes
	float dx = sin(s->heading) * (s->speed);
	float dy = -cos(s->heading) * (s->speed);

	//change positions

	s->sx += dx;
	s->sy += dy;
	return;
}




