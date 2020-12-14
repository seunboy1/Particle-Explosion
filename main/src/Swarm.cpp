#include "../include/Swarm.h"
Swarm::Swarm() {
	m_pParticles  = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
	delete[]m_pParticles;
}

void Swarm::update(){
	for (int i = 0; i < Swarm::NPARTICLES; i++) {
		m_pParticles[i].update();
	}
} 