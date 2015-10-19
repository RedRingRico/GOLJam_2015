#ifndef __GOLJ_RENDERER_HPP__
#define __GOLJ_RENDERER_HPP__

#include <DataTypes.hpp>
#include <SDL2/SDL.h>

namespace GOL
{
	class GameWindow;

	class Renderer
	{
	public:
		Renderer( );
		~Renderer( );

		GOL_UINT32 Initialise( GameWindow &p_GameWindow );
		void Terminate( );

		void Clear( );
		void SwapBuffers( );

	private:
		SDL_Window		*m_pWindow;
		SDL_GLContext	m_GLContext;
	};
}

#endif // __GOLJ_RENDERER_HPP__

