
#ifdef __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#else // __APPLE__

#endif

#include <iostream>
#include <vector>

#include "Assets.h"
#include "level.h"
//SDL
SDL_Window* window;
SDL_Renderer* renderer;

//GFX
std::vector<SDL_Texture*> textures; 

//Exit condition
bool quit = false;

//Level
Level level(32,24);

//Functions
void InitSDL();
void LoadAssets();
void LoadTexture( std::string s );

int main()
{
    //INIT
    InitSDL();
    LoadAssets();
    
    level.SetLevel(0);
    
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
        
        for( int i=0; i < 32; ++i )
        {
            for( int j=0; j < 24; ++j )
            {
                int tid = level.at(i,j).n;
                std::cout << tid << std::endl;
                SDL_Rect dst { i*32, j*32, 32, 32 };
                SDL_RenderCopy( renderer, textures[tid], NULL, &dst );
            }
        }
        
        //SDL_RenderCopy( renderer, textures[0] , NULL, NULL );
        //SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
        SDL_RenderPresent( renderer );
        
    }
    
    return 0;
}

void InitSDL()
{
    SDL_Init( SDL_INIT_EVERYTHING );
    window = SDL_CreateWindow( "GGJ15", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 768, SDL_WINDOW_SHOWN );
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}


void LoadAssets()
{
    for( std::string s : assets )
    {
        LoadTexture( s );
    }
}

void LoadTexture( std::string file )
{
    SDL_Surface* sur = IMG_Load( file.c_str() );
    SDL_Texture* tex = SDL_CreateTextureFromSurface( renderer, sur );
    SDL_FreeSurface( sur );
    textures.push_back( tex );
}
