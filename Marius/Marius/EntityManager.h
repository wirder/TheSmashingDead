#pragma once
#include <SFML/Graphics.hpp>
#include "AbstractEntity.h"

using namespace sf;
using namespace std;

class EntityManager {
public:
	AbstractEntity *create (std::string type);
};

