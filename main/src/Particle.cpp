#include "../include/Particle.h"
#include <stdlib.h>

Particle::Particle() {
	m_x = ((2.0 *rand()) / RAND_MAX) - 1; //random number between -1  and 1
	m_y = ((2.0 * rand()) / RAND_MAX) - 1;
}


Particle::~Particle() {}

void Particle::update() { //Changing the position of the particles
	const double speed = 0.01;
	m_x += speed;
	m_y += speed;
}
