#pragma once
#include "Particle.h"
//Manage collection of particles 
class Swarm
{
	Particle*  m_pParticles;

public:
	const static int NPARTICLES = 5000;
	Swarm();
	virtual ~Swarm();
	void update();
	const Particle* const getParticles() { return m_pParticles; }

};

