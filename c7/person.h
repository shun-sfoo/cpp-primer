#ifndef PERSON_H
#define PERSON_H
#include <istream>
#include <ostream>
#include <string>
using std::istream;
using std::ostream;
using std::string;

class Person {
  friend istream& read(istream&, Person&);
  friend ostream& print(ostream&, const Person&);

 public:
  Person() = default;
  Person(istream&);
  Person(const string& n, const string& addr) : name(n), address(addr) {}
  string get_name() const { return name; }
  string get_address() const { return address; }

 private:
  string name;
  string address;
};

istream& read(istream&, Person&);
ostream& print(ostream&, const Person&);

#endif
