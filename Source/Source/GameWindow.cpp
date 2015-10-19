#include <GameWindow.hpp>

namespace GOL
{
	GameWindow::GameWindow( ) :
		m_pWindow( GOL_NULL ),
		m_pSurface( GOL_NULL ),
		m_Width( 0UL ),
		m_Height( 0UL )
	{
	}

	GameWindow::~GameWindow( )
	{
		this->Terminate( );
	}

	GOL_UINT32 GameWindow::Initialise( const WindowAttributes p_Attributes,
			const GOL_UINT32 p_Width, const GOL_UINT32 p_Height )
	{
		if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER |
			SDL_INIT_JOYSTICK ) < 0 )
		{
			return GOL_FAIL;
		}

		SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3 );
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK,	
			SDL_GL_CONTEXT_PROFILE_CORE );

		SDL_GL_SetAttribute( SDL_GL_BUFFER_SIZE, 32 );
		SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
		SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 24 );
		SDL_GL_SetAttribute( SDL_GL_STENCIL_SIZE, 8 );
		SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8 );
		SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
		SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 );
		SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );

		m_pWindow = SDL_CreateWindow( "Red Ring Rico's GOL Jam Entry",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			p_Width, p_Height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL );

		if( !m_pWindow )
		{
			return GOL_FAIL;
		}

		m_Width = p_Width;
		m_Height = p_Height;

		return GOL_OK;
	}

	void GameWindow::Terminate( )
	{
		if( m_pWindow != GOL_NULL )
		{
			SDL_DestroyWindow( m_pWindow );
			m_pWindow = GOL_NULL;
		}
	}

	SDL_Window *GameWindow::GetWindow( ) const
	{
		return m_pWindow;
	}

	GOL_UINT32 GameWindow::GetWidth( ) const
	{
		return m_Width;
	}

	GOL_UINT32 GameWindow::GetHeight( ) const
	{
		return m_Height;
	}
}

