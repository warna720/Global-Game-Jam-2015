
#ifdef __linux__
#include <SDL2/SDL.h>
#else // __APPLE__

#endif


SDL_Window* window;
SDL_Renderer* renderer;

bool quit = false;

int main()
{
    //INIT
    SDL_Init( SDL_INIT_EVERYTHING );
    window = SDL_CreateWindow( "GGJ15", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE );
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    while( !quit )
    {
        SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
        
        //Input?
        
        //Draw?
        
        
        
        SDL_RenderClear( renderer );
        SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
        SDL_RenderPresent( renderer );
        
    }
    
    return 0;
}
