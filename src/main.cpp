#include "stdafx.hpp"
#include "Game.hpp"



auto main() -> int {
   auto game = std::make_unique<Game>();
   game->run();

}
