#ifndef SCREEN_H
#define SCREEN_H
#include <ostream>
#include <string>

using std::ostream;
using std::string;

class Screen {
  friend class Window_mgr;

 public:
  typedef string::size_type pos;
  Screen() = default;
  Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
  Screen(pos ht, pos wd, char c)
      : height(ht), width(wd), contents(ht * wd, c) {}
  char get() const { return contents[cursor]; }
  inline char get(pos ht, pos wd) const;
  Screen& move(pos r, pos c);
  Screen& set(char);
  Screen& set(pos, pos, char);
  const Screen& display(ostream& os) const {
    do_display(os);
    return *this;
  }

  Screen& display(ostream& os) {
    do_display(os);
    return *this;
  }

 private:
  pos cursor = 0;
  pos height = 0, width = 0;
  string contents;
  void do_display(ostream& os) const { os << contents; }
};

inline Screen& Screen::move(pos r, pos c) {
  pos row = r * width;
  cursor = row + c;
  return *this;
}

inline char Screen::get(pos ht, pos wd) const {
  return contents[ht * width + wd];
}

inline Screen& Screen::set(char c) {
  contents[cursor] = c;
  return *this;
}

inline Screen& Screen::set(pos r, pos col, char ch) {
  contents[r * width + col] = ch;
  return *this;
}

#endif
