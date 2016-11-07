// EventManager.cpp

// HI Includes
#include <HI/EventManager.hpp>
// SDL2 Includes
#include <SDL2/SDL.h>

namespace HI
{
  bool EventManager::Initialize()
  {
    if (SDL_Init(SDL_INIT_EVENTS) < 0)
    {
      SDL_Log("Failed to initialize SDL events: %s", SDL_GetError());
      return false;
    }

    return true;
  }

  void EventManager::Finalize()
  {
    SDL_Quit();
  }

  void EventManager::Poll()
  {
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
      switch (e.type)
      {
        case SDL_APP_DIDENTERBACKGROUND:
          ApplicationEnteredBackground();
          break;
        case SDL_APP_DIDENTERFOREGROUND:
          ApplicationEnteredForeground();
          break;
        case SDL_APP_LOWMEMORY:
          ApplicationLowMemory();
          break;
        case SDL_APP_TERMINATING:
          ApplicationTerminating();
          break;
        case SDL_APP_WILLENTERBACKGROUND:
          ApplicationEnteringBackground();
          break;
        case SDL_APP_WILLENTERFOREGROUND:
          ApplicationEnteringForeground();
          break;
        case SDL_AUDIODEVICEADDED:
          AudioDeviceAdded();
          break;
        case SDL_AUDIODEVICEREMOVED:
          AudioDeviceRemoved();
          break;
        case SDL_CLIPBOARDUPDATE:
          ClipboardUpdated();
          break;
        case SDL_CONTROLLERAXISMOTION:
          ControllerAxisMoved(static_cast<PlayerIndex>(e.cdevice.which), static_cast<ControllerAxis>(e.caxis.axis), e.caxis.value);
          break;
        case SDL_CONTROLLERBUTTONDOWN:
          ControllerButtonPressed(static_cast<PlayerIndex>(e.cdevice.which), static_cast<ControllerButton>(e.cbutton.button));
          break;
        case SDL_CONTROLLERBUTTONUP:
          ControllerButtonReleased(static_cast<PlayerIndex>(e.cdevice.which), static_cast<ControllerButton>(e.cbutton.button));
          break;
        case SDL_CONTROLLERDEVICEADDED:
          ControllerDeviceAdded(static_cast<PlayerIndex>(e.cdevice.which));
          break;
        case SDL_CONTROLLERDEVICEREMAPPED:
          ControllerDeviceRemapped(static_cast<PlayerIndex>(e.cdevice.which));
          break;
        case SDL_CONTROLLERDEVICEREMOVED:
          ControllerDeviceRemoved(static_cast<PlayerIndex>(e.cdevice.which));
          break;
        case SDL_DOLLARGESTURE:
          DollarGestured();
          break;
        case SDL_DOLLARRECORD:
          DollarRecorded();
          break;
//      case SDL_DROPBEGIN:
//        DropBegan();
//        break;
//      case SDL_DROPCOMPLETE:
//        DropCompleted();
//        break;
        case SDL_DROPFILE:
          DroppedFile(std::string(e.drop.file));
          SDL_free(e.drop.file);
          break;
//      case SDL_DROPTEXT:
//        DroppedText();
//        break;
        case SDL_FINGERDOWN:
          TouchPressed();
          break;
        case SDL_FINGERMOTION:
          TouchMoved();
          break;
        case SDL_FINGERUP:
          TouchReleased();
          break;
        case SDL_KEYDOWN:
          KeyPressed(static_cast<Key>(e.key.keysym.sym), static_cast<KeyMods>(e.key.keysym.mod), e.key.repeat != 0);
          break;
        case SDL_KEYUP:
          KeyReleased(static_cast<Key>(e.key.keysym.sym), static_cast<KeyMods>(e.key.keysym.mod), e.key.repeat != 0);
          break;
        case SDL_JOYAXISMOTION:
          JoystickAxisMoved();
          break;
        case SDL_JOYBALLMOTION:
          JoystickBallMoved();
          break;
        case SDL_JOYBUTTONDOWN:
          JoystickButtonPressed();
          break;
        case SDL_JOYBUTTONUP:
          JoystickButtonReleased();
          break;
        case SDL_JOYDEVICEADDED:
          JoystickDeviceAdded();
          break;
        case SDL_JOYDEVICEREMOVED:
          JoystickDeviceRemoved();
          break;
        case SDL_JOYHATMOTION:
          JoystickHatMoved();
          break;
        case SDL_MOUSEBUTTONDOWN:
          MouseButtonPressed(static_cast<MouseButton>(e.button.button), e.button.x, e.button.y);
          break;
        case SDL_MOUSEBUTTONUP:
          MouseButtonReleased(static_cast<MouseButton>(e.button.button), e.button.x, e.button.y);
          break;
        case SDL_MOUSEMOTION:
          MouseMoved(e.motion.x, e.motion.y, e.motion.xrel, e.motion.yrel);
          break;
        case SDL_MOUSEWHEEL:
          MouseWheelScrolled(e.wheel.x, e.wheel.y);
          break;
        case SDL_MULTIGESTURE:
          MultiGestured();
          break;
        case SDL_QUIT:
          Quit();
          break;
        case SDL_SYSWMEVENT:
          SystemEvent();
          break;
        case SDL_TEXTEDITING:
          TextEditing();
          break;
        case SDL_TEXTINPUT:
          TextInput();
          break;
        case SDL_USEREVENT:
          UserEvent();
          break;
        case SDL_WINDOWEVENT:
          switch (e.window.event)
          {
            case SDL_WINDOWEVENT_CLOSE:
              WindowClosed();
              break;
            case SDL_WINDOWEVENT_ENTER:
              WindowEntered();
              break;
            case SDL_WINDOWEVENT_EXPOSED:
              WindowExposed();
              break;
            case SDL_WINDOWEVENT_FOCUS_GAINED:
              WindowFocused();
              break;
            case SDL_WINDOWEVENT_FOCUS_LOST:
              WindowBlurred();
              break;
            case SDL_WINDOWEVENT_HIDDEN:
              WindowHidden();
              break;
            case SDL_WINDOWEVENT_LEAVE:
              WindowExited();
              break;
            case SDL_WINDOWEVENT_MAXIMIZED:
              WindowMaximized();
              break;
            case SDL_WINDOWEVENT_MINIMIZED:
              WindowMinimized();
              break;
            case SDL_WINDOWEVENT_MOVED:
              WindowMoved(e.window.data1, e.window.data2);
              break;
            case SDL_WINDOWEVENT_RESIZED:
              WindowResized(e.window.data1, e.window.data2);
              break;
            case SDL_WINDOWEVENT_RESTORED:
              WindowRestored();
              break;
            case SDL_WINDOWEVENT_SHOWN:
              WindowShown();
              break;
          }
          break;
      }
    }
  }
}
