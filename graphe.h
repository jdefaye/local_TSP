#ifndef GRAPHE_H
#define GRAPHE_H

#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <vector>
<<<<<<< HEAD
=======
#include <ctime>
>>>>>>> 519644312f8c69484c5d3594f90f9c7dd5b800fc

#include "loader.h"
#include "city.h"

class Graph {
  private:
    std::string filename;
    int nb_city;
    std::vector<City> cities;
    float ** distances;
<<<<<<< HEAD
=======
    static int * configuration;
>>>>>>> 519644312f8c69484c5d3594f90f9c7dd5b800fc
    
  public:
    Graph();
    Graph(std::string filename);
    Graph(std::vector<City> cities);
    
    /**	GETTERS	**/
    std::string get_filename() { return filename; }
    
    int get_nbCity() { return nb_city; }
    
    std::vector<City> get_cities() { return cities; }
    
    float ** get_distances() { return distances; }
    
    
    /**	SETTERS	**/
    void set_filename(std::string filename) { this->filename; }
    
    void set_nbCity(int nb_city) { this->nb_city = nb_city; }
    
    void set_cities(std::vector<City> cities) { this->cities = cities; }
    
    void set_distances(float ** distances) { free(this->distances);	this->distances = distances; }
    
    /**	AFFICHAGE	**/
    std::ostream& print(std::ostream& out) const;

    friend std::ostream& operator<<(std::ostream& out, Graph & g) { return g.print(out); }

    friend std::ostream& operator<<(std::ostream& out, const Graph & g) { return g.print(out); }
    
<<<<<<< HEAD
=======
    void load_instance(char * filename);
    
>>>>>>> 519644312f8c69484c5d3594f90f9c7dd5b800fc
    void build_matrix();
    
    float compute_distance(City A, City B);
    
<<<<<<< HEAD
    
=======
    /** AUTRES METHODES **/
    
    /*
     * Construit une solution aléatoire
     */
    static void init();
    
    
    /*
     * Evalue la configuration
     */
    float eval() const;
>>>>>>> 519644312f8c69484c5d3594f90f9c7dd5b800fc
};

#endif