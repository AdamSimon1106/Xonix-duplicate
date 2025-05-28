#pragma once

#include <SFML/Graphics.hpp>
#include "GridManager.h"
#include "Enemy.h"

class AreaCloser{
public:
	AreaCloser(GridManager& gridManager);
	
	
private:
	GridManager& m_gridMannager;
};