#include "loader.h"

using namespace std;


Loader::Loader() : nom_fichier("")
{}


Loader::Loader(string nom_fichier) : nom_fichier(nom_fichier)
{}

string Loader::get_file_name() const
{
  return nom_fichier;
}

void Loader::set_file_name(string nom_fichier)
{
  this->nom_fichier = nom_fichier;
}



City Loader::read_line(const string& line, char sep)
{
  int x, y, id;
  stringstream ss(line);
  string tmp;
  getline(ss, tmp, sep); // lecture de l'id
  id = atoi(tmp.c_str());
  
  getline(ss, tmp, sep); // lecture de l'abscisse
  x = atoi(tmp.c_str());
  
  getline(ss, tmp, sep); // lecture de l'ordonnée
  y = atoi(tmp.c_str());
  
  City ville(id, x, y);
  return ville;
}


void Loader::read_first_line(const string& line)
{
  stringstream ss(line);
  string tmp, tmp2;
  getline(ss, tmp);
  tmp2 = tmp.substr(tmp.size() - 3, 3);
  nb_ville = atoi(tmp2.c_str());
}


vector<City> Loader::load()
{
  ifstream fichier(nom_fichier.c_str());
  if (fichier) {
    string ligne;
    getline(fichier, ligne);
    read_first_line(ligne);
    tableau_ville.reserve(nb_ville);
    tableau_ville.resize(nb_ville);
    for (int i = 0; i < 5; ++i) getline(fichier, ligne);
    for (int i = 0; i < nb_ville; ++i) {
      getline(fichier, ligne);
      City ville = read_line(ligne, ' ');
      tableau_ville[i] = ville;
    }
  }
  else cerr << "Impossible d'ouvrir le fichier : " << nom_fichier << " !" << endl;
  return tableau_ville;
}

void Loader::print()
{
  for (int i = 0; i < tableau_ville.size(); ++i) {
    cout << "ville : " << tableau_ville[i].get_id() << " " << tableau_ville[i].get_x() << " " << tableau_ville[i].get_y() << endl;
  }
}


