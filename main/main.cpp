
#include <SDL.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>

#include "include/Swarm.h"
#include "include/Screen.h"

int main(int argc, char** argv) {
	srand(time(NULL));//srands seeds the random number generator which makes it produce a sequence number at a time 
	Screen screen;

	if (screen.init() == false) {
		std::cout << "Error initialising SDL." << std::endl;
	}

	bool quit = false;
	SDL_Event event;
	//screen.init();

	Swarm swarm;

	while (!quit) { // aka game loop 
		
		int elapsed = SDL_GetTicks();//this gets the no of milliseconds since the SDL library initialization i.e it returns random positive incremental no

		
		//screen.clear();//tHis sets the screen to black 
		swarm.update();

		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128); //random number between 1- 256 
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);
		
		const Particle* const pParticles = swarm.getParticles();
		
		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2; // calculate the position of the particles
			int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue );
		}
		
		/*
		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, red, green, blue);
			}
		}
		*/

		//Draw the screen
		screen.update();//This updates whatever changes you have made to the screen  

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}

	}
	
	screen.close();
	return EXIT_SUCCESS;
}