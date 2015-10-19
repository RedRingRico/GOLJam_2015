#include <GitVersion.hpp>
#include <CLOC.hpp>
#include <GameWindow.hpp>
#include <Renderer.hpp>
#include <iostream>
#include <SDL2/SDL.h>

int main( int p_Argc, char **p_ppArgv )
{
	std::cout << "Red Ring Rico's GOL Jam Entry" << std::endl;
	std::cout << "Build information" << std::endl;
	std::cout << "\tVersion:    " << GIT_BUILD_VERSION << std::endl;
	std::cout << "\tTag:        " << GIT_TAG_NAME << std::endl;
	std::cout << "\tLine count: " << CLOC_LINECOUNT << std::endl;

	GOL::GameWindow TestWindow;

	TestWindow.Initialise( GOL::WindowAttributes::Move, 1280, 720 );

	GOL::Renderer TestRenderer;

	TestRenderer.Initialise( TestWindow );

	GOL_BOOL Run = GOL_TRUE;
	SDL_Event Event;

	while( Run )
	{
		while( SDL_PollEvent( &Event ) != 0 )
		{
			if( Event.type == SDL_QUIT )
			{
				Run = GOL_FALSE;
			}

			const Uint8 *KeyState = SDL_GetKeyboardState( GOL_NULL );

			if( KeyState[ SDL_SCANCODE_ESCAPE ] )
			{
				Run = GOL_FALSE;
			}
		}

		TestRenderer.Clear( );
		TestRenderer.SwapBuffers( );
	}

	return 0;
}

