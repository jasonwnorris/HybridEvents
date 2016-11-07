// main.cpp

// HI Includes
#include <HI/EventManager.hpp>

bool g_IsRunning = true;

void OnQuit()
{
  g_IsRunning = false;
}

int main(int p_ArgCount, char** p_ArgVars)
{
  SDL_Log("HybridInput");

  HI::EventManager manager;
  manager.Quit.Add(OnQuit);

  if (!manager.Initialize())
  {
    return -1;
  }

  while (g_IsRunning)
  {
    manager.Poll();
  }

  manager.Finalize();

  return 0;
}
