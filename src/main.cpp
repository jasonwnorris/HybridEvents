// main.cpp

// HE Includes
#include <HE/EventManager.hpp>

bool g_IsRunning = true;
SDL_Rect g_Rectangle;

void OnMouseButtonPressed(HI::MouseButton p_Button, int p_X, int p_Y)
{
  SDL_Log("\"MouseButtonPressed\" event has been fired.");

  switch (p_Button)
  {
    case HI::MouseButton::Left:
      g_Rectangle.x = p_X;
      g_Rectangle.y = p_Y;
      break;
    case HI::MouseButton::Right:
      g_Rectangle.w = p_X - g_Rectangle.x;
      g_Rectangle.h = p_Y - g_Rectangle.y;
      break;
    case HI::MouseButton::Middle:
    case HI::MouseButton::Extra1:
    case HI::MouseButton::Extra2:
      break;
  }
}

void OnQuit()
{
  SDL_Log("\"Quit\" event has been fired.");

  g_IsRunning = false;
}

int main(int p_ArgCount, char** p_ArgVars)
{
  HI::EventManager manager;
  manager.MouseButtonPressed.Add(OnMouseButtonPressed);
  manager.Quit.Add(OnQuit);

  if (!manager.Initialize())
  {
    SDL_Log("Failed to initialize event manager.");
    return -1;
  }

  if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
  {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to initialize video subsystem: %s", SDL_GetError());
    return -1;
  }

  SDL_Window* window = SDL_CreateWindow("HybridInput", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
  if (window == nullptr)
  {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to initialize the window.");
    return -1;
  }

  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == nullptr)
  {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to initialize the renderer.");
    return -1;
  }

  while (g_IsRunning)
  {
    manager.Poll();

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &g_Rectangle);

    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_QuitSubSystem(SDL_INIT_VIDEO);

  manager.Finalize();

  return 0;
}
