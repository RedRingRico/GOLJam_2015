#ifndef __GOLJ_GAME_HPP__
#define __GOLJ_GAME_HPP__

#include <DataTypes.hpp>
#include <Renderer.hpp>
#include <GameWindow.hpp>

namespace GOL
{
	class Game
	{
	public:
		Game( );
		~Game( );

		GOL_UINT32 Initialise( );

		GOL_UINT32 Execute( );

	private:
		GameWindow	m_Window;
		Renderer	m_Renderer;
	};
}

#endif // __GOLJ_GAME_HPP__

