// ControllerButton.hpp

#ifndef __HI_CONTROLLERBUTTON_HPP__
#define __HI_CONTROLLERBUTTON_HPP__

// SDL2 Includes
#include <SDL2/SDL.h>

enum class ControllerButton : unsigned char
{
  A = SDL_CONTROLLER_BUTTON_A,
  B = SDL_CONTROLLER_BUTTON_B,
  X = SDL_CONTROLLER_BUTTON_X,
  Y = SDL_CONTROLLER_BUTTON_Y,
  Start = SDL_CONTROLLER_BUTTON_START,
  Back = SDL_CONTROLLER_BUTTON_BACK,
  Guide = SDL_CONTROLLER_BUTTON_GUIDE,
  LeftShoulder = SDL_CONTROLLER_BUTTON_LEFTSHOULDER,
  RightShoulder = SDL_CONTROLLER_BUTTON_RIGHTSHOULDER,
  LeftStick = SDL_CONTROLLER_BUTTON_LEFTSTICK,
  RightStick = SDL_CONTROLLER_BUTTON_RIGHTSTICK,
  DirectionUp = SDL_CONTROLLER_BUTTON_DPAD_UP,
  DirectionDown = SDL_CONTROLLER_BUTTON_DPAD_DOWN,
  DirectionLeft = SDL_CONTROLLER_BUTTON_DPAD_LEFT,
  DirectionRight = SDL_CONTROLLER_BUTTON_DPAD_RIGHT,
};

#endif
