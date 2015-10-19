#include <Game.hpp>
#include <SDL2/SDL.h>

namespace GOL
{
	Game::Game( )
	{
	}

	Game::~Game( )
	{
	}

	GOL_UINT32 Game::Initialise( )
	{
		if( m_Window.Initialise( WindowAttributes::Move, 1280, 720 ) !=
			GOL_OK )
		{
			return GOL_FAIL;
		}

		if( m_Renderer.Initialise( m_Window ) != GOL_OK )
		{
			return GOL_FAIL;
		}

		return GOL_OK;
	}

	GOL_UINT32 Game::Execute( )
	{
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

			m_Renderer.Clear( );
			m_Renderer.SwapBuffers( );
		}

		return GOL_OK;
	}
}

