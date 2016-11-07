// EventManager.hpp

#ifndef __HI_EVENTMANAGER_HPP__
#define __HI_EVENTMANAGER_HPP__

// HI Includes
#include <HI/ControllerAxis.hpp>
#include <HI/ControllerButton.hpp>
#include <HI/Key.hpp>
#include <HI/KeyMods.hpp>
#include <HI/MouseButton.hpp>
#include <HI/PlayerIndex.hpp>
// HD Includes
#include <HD/Delegate.hpp>
// STL Includes
#include <string>

namespace HI
{
  class EventManager
  {
    public:
      bool Initialize();
      void Finalize();

      void Poll();

      HD::Delegate<void> ApplicationEnteredBackground;
      HD::Delegate<void> ApplicationEnteredForeground;
      HD::Delegate<void> ApplicationEnteringBackground;
      HD::Delegate<void> ApplicationEnteringForeground;
      HD::Delegate<void> ApplicationLowMemory;
      HD::Delegate<void> ApplicationTerminating;
      HD::Delegate<void> AudioDeviceAdded;
      HD::Delegate<void> AudioDeviceRemoved;
      HD::Delegate<void> ClipboardUpdated;
      HD::Delegate<void, PlayerIndex, ControllerAxis, short> ControllerAxisMoved;
      HD::Delegate<void, PlayerIndex, ControllerButton> ControllerButtonPressed;
      HD::Delegate<void, PlayerIndex, ControllerButton> ControllerButtonReleased;
      HD::Delegate<void, PlayerIndex> ControllerDeviceAdded;
      HD::Delegate<void, PlayerIndex> ControllerDeviceRemapped;
      HD::Delegate<void, PlayerIndex> ControllerDeviceRemoved;
      HD::Delegate<void> DollarGestured;
      HD::Delegate<void> DollarRecorded;
//    HD::Delegate<void> DropBegan;
//    HD::Delegate<void> DropCompleted;
      HD::Delegate<void, const std::string&> DroppedFile;
//    HD::Delegate<void, const std::string&> DroppedText;
      HD::Delegate<void> JoystickAxisMoved;
      HD::Delegate<void> JoystickBallMoved;
      HD::Delegate<void> JoystickButtonPressed;
      HD::Delegate<void> JoystickButtonReleased;
      HD::Delegate<void> JoystickDeviceAdded;
      HD::Delegate<void> JoystickDeviceRemoved;
      HD::Delegate<void> JoystickHatMoved;
      HD::Delegate<void, Key, KeyMods, bool> KeyPressed;
      HD::Delegate<void, Key, KeyMods, bool> KeyReleased;
      HD::Delegate<void> TouchMoved;
      HD::Delegate<void> TouchPressed;
      HD::Delegate<void> TouchReleased;
      HD::Delegate<void, MouseButton, int, int> MouseButtonPressed;
      HD::Delegate<void, MouseButton, int, int> MouseButtonReleased;
      HD::Delegate<void, int, int, int, int> MouseMoved;
      HD::Delegate<void, int, int> MouseWheelScrolled;
      HD::Delegate<void> MultiGestured;
      HD::Delegate<void> Quit;
      HD::Delegate<void> SystemEvent;
      HD::Delegate<void> TextEditing;
      HD::Delegate<void> TextInput;
      HD::Delegate<void> UserEvent;
      HD::Delegate<void> WindowBlurred;
      HD::Delegate<void> WindowClosed;
      HD::Delegate<void> WindowEntered;
      HD::Delegate<void> WindowExposed;
      HD::Delegate<void> WindowFocused;
      HD::Delegate<void> WindowHidden;
      HD::Delegate<void> WindowExited;
      HD::Delegate<void> WindowMaximized;
      HD::Delegate<void> WindowMinimized;
      HD::Delegate<void, int, int> WindowMoved;
      HD::Delegate<void, int, int> WindowResized;
      HD::Delegate<void> WindowRestored;
      HD::Delegate<void> WindowShown;
  };
}

#endif
