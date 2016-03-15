#ifndef CITY_H
#define CITY_H

#include <iostream>

class City {
  private:
    int id;
    int x;
    int y;
    
  public:
    City();
    
    City(int id, int x, int y);
    
    /**	GETTERS	**/
    int get_id() { return id; }
    
    int get_x() { return x; }
    
    int get_y() { return y; }
    
    /**	SETTERS	**/
    void set_id(int id) { this->id = id; }
    
    void set_x(int x) { this->x = x; }
    
    void set_y(int y) { this->y = y; }
    
    /**	AFFICHAGE	**/
    std::ostream& print(std::ostream& out) const;

    friend std::ostream& operator<<(std::ostream& out, City & c) { return c.print(out); }

    friend std::ostream& operator<<(std::ostream& out, const City & c) { return c.print(out); }
    
};

#endif