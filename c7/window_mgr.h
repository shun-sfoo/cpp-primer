#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H
#include <vector>
#include "screen.h"

using std::vector;

class Window_mgr {
 public:
  using ScreenIndex = vector<Screen>::size_type;
  void clear(ScreenIndex);
  ScreenIndex addScreen(const Screen&);

 private:
  vector<Screen> screens{Screen(24, 80, ' ')};
};

#endif
