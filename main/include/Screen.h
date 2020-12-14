#pragma once
#include <SDL.h>
#include <string.h>
class Screen
{
public:
    const static int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;
    Screen();
    bool init();
    bool processEvents();
    void close();
    void update();
    void clear();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    SDL_Texture* m_texture;
    Uint32* m_buffer;


};

