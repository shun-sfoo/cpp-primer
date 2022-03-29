#include "person.h"

istream& read(istream& is, Person& item) {
  is >> item.name >> item.address;
  return is;
}

ostream& print(ostream& os, const Person& item) {
  os << item.get_name() << " " << item.get_address();
  return os;
}

Person::Person(istream& is) {
  read(is, *this);
}
