#pragma once

//SFML 
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

//Core
#include <memory>
#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <list>
#include <map>
#include <cmath>
#include <filesystem>

//Windows
#include <windows.h>

//Own Structures
class State;
class StateData;
class GFXSettings;

typedef unsigned short u_short;
enum Direction { IDLE = 0, LEFT, RIGHT, UP, DOWN };
bool isAnyKeyPressed();
