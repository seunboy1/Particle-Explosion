#pragma once
struct Particle
{
	double m_x;
	double m_y;

	Particle();
	virtual ~Particle();
	void update(); // This updates the position of the particles 

}; 

