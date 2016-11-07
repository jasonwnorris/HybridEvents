// MouseButton.hpp

#ifndef __HI_MOUSEBUTTON_HPP__
#define __HI_MOUSEBUTTON_HPP__

// SDL2 Includes
#include <SDL2/SDL.h>

namespace HI
{
  enum class MouseButton : unsigned char
  {
    Left = SDL_BUTTON_LEFT,
    Middle = SDL_BUTTON_MIDDLE,
    Right = SDL_BUTTON_RIGHT,
    Extra1 = SDL_BUTTON_X1,
    Extra2 = SDL_BUTTON_X2,
  };
}

#endif
