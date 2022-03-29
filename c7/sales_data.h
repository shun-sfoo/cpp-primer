#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <istream>
#include <ostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;

class Sales_data {
  friend Sales_data add(const Sales_data&, const Sales_data&);
  friend istream& read(istream&, const Sales_data&);
  friend ostream& print(ostream&, const Sales_data&);

 public:
  Sales_data() = default;
  explicit Sales_data(istream& is);
  explicit Sales_data(const string& s) : bookNo(s) {}
  Sales_data(const string& s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {}

  string isbn() const { return bookNo; }
  Sales_data& combine(const Sales_data&);

 private:
  inline double avg_price() const {
    return units_sold ? revenue / units_sold : 0;
  };
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

istream& read(istream&, const Sales_data&);
Sales_data add(const Sales_data&, const Sales_data&);
ostream& print(ostream&, const Sales_data&);

#endif
