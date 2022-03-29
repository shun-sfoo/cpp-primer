#include "screen.h"
#include "window_mgr.h"

void Window_mgr::clear(ScreenIndex i) {
  Screen& s = screens[i];
  s.contents = string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen& s) {
  screens.push_back(s);
  return screens.size() - 1;
}
