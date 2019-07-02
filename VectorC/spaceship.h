#pragma once

static float ACCELERATE_SHIP = 2.0f;
static float MAX_SPEED = 50.0f;
static float ROTATE_DELTA = 0.13f;
static float DECELERATE_SHIP = 2.0f;


typedef struct {
	float sx;
	float sy;
	float heading;
	float speed;
	int gone;


} Spaceship;

Spaceship* createship();
void ship_accelerate(Spaceship* s);

void ship_decelerate(Spaceship* s);

void ship_position(Spaceship* s);
void destroy_ship(Spaceship* s);