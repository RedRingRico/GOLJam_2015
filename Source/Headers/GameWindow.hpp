#ifndef __GOLJ_GAMEWINDOW_HPP__
#define __GOLJ_GAMEWINDOW_HPP__

#include <SDL2/SDL.h>
#include <DataTypes.hpp>

namespace GOL
{
	enum class WindowAttributes : GOL_UINT32
	{
		Maximise = 1,
		Resize = 2,
		Move = 4,
		Fullscreen = 5
	};

	class GameWindow
	{
	public:
		GameWindow( );
		~GameWindow( );

		GOL_UINT32 Initialise( const WindowAttributes p_Attributes,
			const GOL_UINT32 p_Width, const GOL_UINT32 p_Height );

		void Terminate( );

		SDL_Window *GetWindow( ) const;

		GOL_UINT32 GetWidth( ) const;
		GOL_UINT32 GetHeight( ) const;

	private:
		SDL_Window	*m_pWindow;
		SDL_Surface	*m_pSurface;

		GOL_UINT32	m_Width;
		GOL_UINT32	m_Height;
	};
}

#endif // __GOLJ_GAMEWINDOW_HPP__

