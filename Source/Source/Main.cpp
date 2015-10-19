#include <GitVersion.hpp>
#include <CLOC.hpp>
#include <Game.hpp>
#include <iostream>

int main( int p_Argc, char **p_ppArgv )
{
	std::cout << "Red Ring Rico's GOL Jam Entry" << std::endl;
	std::cout << "Build information" << std::endl;
	std::cout << "\tVersion:    " << GIT_BUILD_VERSION << std::endl;
	std::cout << "\tTag:        " << GIT_TAG_NAME << std::endl;
	std::cout << "\tLine count: " << CLOC_LINECOUNT << std::endl;

	GOL::Game TheGame;

	if( TheGame.Initialise( ) != GOL_OK )
	{
		return GOL_FAIL;
	}

	return TheGame.Execute( );
}

