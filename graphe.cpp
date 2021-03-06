#include "graphe.h"

using namespace std;

vector<int> Graph::configuration;

Graph::Graph() {}

Graph::Graph(std::string filename) {
    Loader L(filename);
    vector<City> city_list = L.load();
    this->filename = filename;
    nb_city = (signed) city_list.size();
    cities =  city_list;
    build_matrix();
}

/*Graph::~Graph()
{
  free(configuration);
}*/


std::ostream& Graph::print(std::ostream& out) const {
  out << "Graphe : " << endl;
  out << "\tFichier : " << filename << endl;
  out << "\tNombre de villes : " << nb_city << endl;
  
  for(City city : cities) {
    out << city << endl;
  }
  
  for(int i=0 ; i<nb_city ; i++) {
    for(int j=0 ; j<nb_city ; j++) {
      out << distances[i][j];
    }
    out << endl;
  }
}

/**
 * Construction de la matrice
 *  à partir de la formule sqrt( pow(x1 - x2, 2) + pow(y1 - y2, 2) )
 */
void Graph::build_matrix() {
  distances = (float **) malloc(nb_city * sizeof(float *));
  for(int i=0 ; i<nb_city ; i++) {
    distances[i] = (float *) malloc(nb_city * sizeof(float ));
  }

  // Parcours de la liste des villes
  City city_1;
  City city_2;
  float distance;
  for(int i=0 ; i<nb_city ; i++) {
    city_1 = cities[i];
    for(int j=i ; j<nb_city ; j++) {
      city_2 = cities[j];
      distance = compute_distance(city_1, city_2);
      distances[i][j] = distance;
      distances[j][i] = distance;
    }
  }
}

/**
 * Calcul de la formule sqrt( pow(A.x - B.x, 2) + pow(A.y - B.y, 2) )
 */
float Graph::compute_distance(City A, City B) {
  return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
}

void Graph::init(const Graph &  G) {
  configuration.resize(G.nb_city);
  for (int i = 0; i < G.nb_city; ++i) {
    configuration[i] = G.cities[i].get_id();
  }
}


void Graph::build_neighbour(int pos_city1, int pos_city2)
{
  if (pos_city1 != pos_city2) {
    if (pos_city1 > pos_city2) {
      int tmp = pos_city1;
      pos_city1 = pos_city2;
      pos_city2 = tmp;
    }
    int nb_it = pos_city2 - ((1 + pos_city2 - pos_city1)/2);
    int tmp, j = 0;
    for (int i = pos_city1; i <= nb_it; ++i) {
      tmp = configuration[i];
      configuration[i] = configuration[pos_city2 - j];
      configuration[pos_city2 - j] = tmp;
      j++;
    }
  }
}





float Graph::eval() const
{
  float retour = 0;
  for (int i = 0; i < (nb_city - 1); ++i) {
    retour += distances[configuration[i] - 1][configuration[i+1] - 1];
  }
  return retour;
}


void Graph::init_alea(const Graph& G)
{
  configuration.resize(G.get_nbCity());
  int tableau_initial[G.get_nbCity()];
  int n, tmp;
  for (int i = 0; i < G.get_nbCity(); ++i) tableau_initial[i] = G.cities[i].get_id();
  for (int i = 0; i < G.get_nbCity(); ++i) {
    n = rand()%(G.get_nbCity() - i);
    configuration[i] = tableau_initial[n];
    tmp = tableau_initial[n];
    tableau_initial[n] = tableau_initial[G.get_nbCity() - i - 1];
    tableau_initial[G.get_nbCity() - i - 1] = tmp;
  }
}

