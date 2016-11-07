// KeyMod.hpp

#ifndef __HI_KEYMOD_HPP__
#define __HI_KEYMOD_HPP__

// SDL2 Includes
#include <SDL2/SDL.h>

enum class KeyMods : int
{
  None = KMOD_NONE,
  LeftShift = KMOD_LSHIFT,
  RightShift = KMOD_RSHIFT,
  Shift = KMOD_LSHIFT | KMOD_RSHIFT,
  LeftControl = KMOD_LCTRL,
  RightControl = KMOD_RCTRL,
  Control = KMOD_LCTRL | KMOD_RCTRL,
  LeftAlt = KMOD_LALT,
  RightAlt = KMOD_RALT,
  Alt = KMOD_LALT | KMOD_RALT,
  LeftGUI = KMOD_LGUI,
  RightGUI = KMOD_RGUI,
  GUI = KMOD_LGUI | KMOD_RGUI,
  Num = KMOD_NUM,
  Caps = KMOD_CAPS,
  Mode = KMOD_MODE,
  Reserved = KMOD_RESERVED,
};

#endif
