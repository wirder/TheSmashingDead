#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class EntityManager {
public:
	AbstractEntity *create (std::string type);
};

