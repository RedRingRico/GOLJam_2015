#include <Renderer.hpp>
#include <GameWindow.hpp>
#include <GL/glew.h>
#include <GL/gl.h>
#include <iostream>

namespace GOL
{
	Renderer::Renderer( )
	{
	}

	Renderer::~Renderer( )
	{
	}

	GOL_UINT32 Renderer::Initialise( GameWindow &p_GameWindow )
	{
		GLenum GLError = GL_NO_ERROR;

		m_pWindow = p_GameWindow.GetWindow( );

		m_GLContext = SDL_GL_CreateContext( m_pWindow );

		if( m_GLContext == GOL_NULL )
		{
			return GOL_FAIL;
		}

		glewExperimental = GL_TRUE;
		GLError = glewInit( );

		if( GLError != GLEW_OK )
		{
			return GOL_FAIL;
		}

		glGetError( );

		std::cout << "[GOL::Renderer::Initialise] <INFO> "
			"Checking for required OpenGL extensions" << std::endl;

		std::cout << "\tARB_texture_storage ... ";

		if( GLEW_ARB_texture_storage == GL_TRUE )
		{
			std::cout << "[OK]" << std::endl;
		}
		else
		{
			std::cout << "[!!]" << std::endl;
			return GOL_FAIL;
		}

		glViewport( 0, 0, p_GameWindow.GetWidth( ),
			p_GameWindow.GetHeight( ) );
		glEnable( GL_DEPTH_TEST );
		glDepthFunc( GL_LEQUAL );

		glClearColor( 1.0f, 0.0f, 0.0f, 1.0f );

		return GOL_OK;
	}

	void Renderer::Terminate( )
	{
	}

	void Renderer::Clear( )
	{
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	}

	void Renderer::SwapBuffers( )
	{
		SDL_GL_SwapWindow( m_pWindow );
	}
}

