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
#include <assert.h>
#define NDEBUG

//Own Structures
class State;
class StateData;
class GFXSettings;

typedef unsigned short u_short;
enum class Direction { IDLE = 0, LEFT, RIGHT, UP, DOWN };
enum class Destination {MAINMENU, GAME, SETTINGS};
bool isAnyKeyPressed();
