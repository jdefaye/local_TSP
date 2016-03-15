#include "city.h"

using namespace std;

City::City() {}


City::City(int id, int x, int y) : id(id), x(x), y(y) {}

ostream& City::print(ostream& out) const {
  out << "Ville :" << endl;
  out << "\t ID = " << id << endl;
  out << "\t X = " << x << endl;
  out << "\t Y = " << y << endl;
  
  return out;
}