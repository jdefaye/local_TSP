#ifndef LOADER_H
#define LOADER_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "city.h"
#include <stdlib.h>

class Loader {
  
  private:
    std::string nom_fichier;
    int nb_ville;
    std::vector<City> tableau_ville;
   
  public:
    
      //Constructeurs
    Loader();
    Loader(std::string nom_fichier);
    
      //Getters et Setter
    std::string get_file_name() const;
    void set_file_name(std::string nom_fichier);
    
    int get_nb_ville() const;
    void set_nb_ville(int nb);
    
      //Méthodes
    void read_first_line(const std::string & line);
    City read_line(const std::string & line, char sep);
    std::vector<City> load();
    void print();
};

#endif