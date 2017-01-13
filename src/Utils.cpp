#include "Utils.h"
namespace Game
{
	bool Utils::IsWalkableTile(Game::Map *map, int X, int Y)
	{
		if (map->Matrix[X][Y] == '0')
			return true;
		if (map->Matrix[X][Y] == '^')
			return true;
		if (map->Matrix[X][Y] == '3')
			return true;
		if (map->Matrix[X][Y] == '$')
			return true;
		if (map->Matrix[X][Y] == '*')
			return true;
		return false;
	}
	bool Utils::IsFlyableTile(Game::Map *map, int X, int Y)
	{
		if (map->Matrix[X][Y] == '0')
			return true;
		if (map->Matrix[X][Y] == '^')
			return true;
		if (map->Matrix[X][Y] == '2')
			return true;
		if (map->Matrix[X][Y] == '3')
			return true;
		if (map->Matrix[X][Y] == '$')
			return true;
		return false;
	}
	bool Utils::CanExplode(Game::Map *map, int X, int Y)
	{
		if (map->Matrix[X][Y] == '1')
			return true;
		return false;
	}
	bool Utils::ShouldExplode(Game::Map *map, int X, int Y)
	{
		if (map->Matrix[X][Y] == '1')
			return true;
		if (map->Matrix[X][Y] == '#')
			return true;
		if (map->Matrix[X][Y] == '*')
			return true;
		return false;
	}
	void Utils::InitInput()
	{
		for (int i = 0; i < 10; i++)
		{
			KeyPressed[i] = false;
		}
	}
	char Utils::DetectInput()
	{
		if (GameEvent->type == sf::Event::KeyPressed)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !KeyPressed[0])
			{
				//KeyPressed[0]=true;
				return 'W';
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !KeyPressed[1])
			{
				//KeyPressed[1]=true;
				return 'A';
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !KeyPressed[2])
			{
				//KeyPressed[2]=true;
				return 'D';
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !KeyPressed[3])
			{
				//KeyPressed[3]=true;
				return 'S';
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !KeyPressed[4])
			{
				//KeyPressed[3]=true;
				return ' ';
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !KeyPressed[5])
			{
				//KeyPressed[3]=true;
				return 'U';
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !KeyPressed[6])
			{
				//KeyPressed[1]=true;
				return 'H';
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !KeyPressed[7])
			{
				//KeyPressed[2]=true;
				return 'J';
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !KeyPressed[8])
			{
				//KeyPressed[3]=true;
				return 'K';
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && !KeyPressed[9])
			{
				//KeyPressed[3]=true;
				return 8;
			}
		}
		else if (GameEvent->type == sf::Event::KeyReleased)
		{
			if (GameEvent->type == sf::Keyboard::W)
			{
				KeyPressed[0] = false;
			}
			else if (GameEvent->type == sf::Keyboard::A)
			{
				KeyPressed[1] = false;
			}
			else if (GameEvent->type == sf::Keyboard::D)
			{
				KeyPressed[2] = false;
			}
			else if (GameEvent->type == sf::Keyboard::S)
			{
				KeyPressed[3] = false;
			}
			else if (GameEvent->type == sf::Keyboard::Space)
			{
				KeyPressed[4] = false;
			}
			else if (GameEvent->type == sf::Keyboard::Up)
			{
				KeyPressed[5] = false;
			}
			else if (GameEvent->type == sf::Keyboard::Left)
			{
				KeyPressed[6] = false;
			}
			else if (GameEvent->type == sf::Keyboard::Right)
			{
				KeyPressed[7] = false;
			}
			else if (GameEvent->type == sf::Keyboard::Down)
			{
				KeyPressed[8] = false;
			}
			else if (GameEvent->type == sf::Keyboard::BackSpace)
			{
				KeyPressed[9] = false;
			}
		}
	}
}
