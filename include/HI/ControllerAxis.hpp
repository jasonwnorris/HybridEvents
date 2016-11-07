// ControllerAxis.hpp

#ifndef __HI_CONTROLLERAXIS_HPP__
#define __HI_CONTROLLERAXIS_HPP__

// SDL2 Includes
#include <SDL2/SDL.h>

namespace HI
{
  enum class ControllerAxis : unsigned char
  {
    LeftX = SDL_CONTROLLER_AXIS_LEFTX,
    LeftY = SDL_CONTROLLER_AXIS_LEFTY,
    RightX = SDL_CONTROLLER_AXIS_RIGHTX,
    RightY = SDL_CONTROLLER_AXIS_RIGHTY,
    TriggerLeft = SDL_CONTROLLER_AXIS_TRIGGERLEFT,
    TriggerRight = SDL_CONTROLLER_AXIS_TRIGGERRIGHT,
  };
}

#endif
