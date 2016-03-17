#ifndef GRAPHE_H
#define GRAPHE_H

#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <ctime>

#include "loader.h"
#include "city.h"

class Graph {
  private:
    std::string filename;
    int nb_city;
    std::vector<City> cities;
    float ** distances;
    
    
  public:
    static int * configuration;
    
    Graph();
    Graph(std::string filename);
    Graph(std::vector<City> cities);
    
    /**	GETTERS	**/
    std::string get_filename() const { return filename; }
    
    int get_nbCity() const { return nb_city; }
    
    std::vector<City> get_cities() const { return cities; }
    
    float ** get_distances() const { return distances; }
    
    
    /**	SETTERS	**/
    void set_filename(std::string filename) { this->filename; }
    
    void set_nbCity(int nb_city) { this->nb_city = nb_city; }
    
    void set_cities(std::vector<City> cities) { this->cities = cities; }
    
    void set_distances(float ** distances) { free(this->distances);	this->distances = distances; }
    
    /**	AFFICHAGE	**/
    std::ostream& print(std::ostream& out) const;

    friend std::ostream& operator<<(std::ostream& out, Graph & g) { return g.print(out); }

    friend std::ostream& operator<<(std::ostream& out, const Graph & g) { return g.print(out); }
    
    void build_matrix();
    
    float compute_distance(City A, City B);
    
    /** AUTRES METHODES **/
    
    /*
     * Construit une solution basé sur le Graph G
     */
    static void init(const Graph &  G);
    
    /*
     * Evalue la configuration
     */
    float eval() const;
    
    /*
     * Construit une solution aléatoire
     */
    static void init_alea(const Graph & G);
};

#endif