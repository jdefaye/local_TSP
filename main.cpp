#include <iostream>

#include "graphe.h"
#include "loader.h"
#include "solution.h"
#include <list>

#define P 500

using namespace std;

/*
int main(int argc, char **argv) {
    srand(time(NULL));
    string chemin_repertoire_instance = "/home/etudiant/Bureau/data/";
    string tableau_instances[7] = {"kroAB100", "kroBC100", "kroCD100", "kroDE100", "kroAE100", "kroAB150", "kroAB200"};
    pair<string, string> tableau_fichier_instances[7] = {make_pair("kroA100.tsp", "kroB100.tsp"),make_pair("kroB100.tsp", "kroC100.tsp"),make_pair("kroC100.tsp", "kroD100.tsp"),make_pair("kroD100.tsp", "kroE100.tsp"),make_pair("kroA100.tsp", "kroE100.tsp"),make_pair("kroA150.tsp", "kroB150.tsp"),make_pair("kroA200.tsp", "kroB200.tsp")};
    
    for (int i = 0; i < 7; ++i) { // Pour les 7 paires d'instances
     vector<pair<float, float > > ensemble_solution;
     list<pair<float, float> > solution_pareto;
     ensemble_solution.resize(P);
     
     string nom_fichier1 = chemin_repertoire_instance + tableau_fichier_instances[i].first;
     string nom_fichier2 = chemin_repertoire_instance + tableau_fichier_instances[i].second;
     
     //Ouverture des deux fichier d'instances en écriture
     ofstream fichier("../resultat/offline500_" + tableau_instances[i] + ".txt", ios::out | ios::trunc);
     ofstream fichier_pareto("../resultat/offlinePareto500_" + tableau_instances[i] + ".txt", ios::out | ios::trunc);
     
     if (fichier&&fichier_pareto) {
      Graph G1(nom_fichier1);
      Graph G2(nom_fichier2);
      
							      // Offline

      
      for (int j = 0; j < P; ++j) {
	G1.init_alea(G1);
	pair<float, float> une_solution = make_pair(G1.eval(), G2.eval());
	ensemble_solution[j] = une_solution;
	fichier << une_solution.first << " " << une_solution.second << endl;
      }
      for (int j = 0; j < P; ++j) {
	bool b = true;
	for (int k = 0; (k < P)&&b; ++k) {
	  if ((ensemble_solution[j].first > ensemble_solution[k].first)&&(ensemble_solution[j].second > ensemble_solution[k].second)) b = false;
	}
	if (b) {
	  solution_pareto.push_back(ensemble_solution[j]);
	  fichier_pareto << ensemble_solution[j].first << " " << ensemble_solution[j].second << endl;
	}
      }
      
      
								// Online

      
      G1.init_alea(G1);
      pair<float, float> une_solution = make_pair(G1.eval(), G2.eval());
      solution_pareto.push_back(une_solution);
      fichier << une_solution.first << " " << une_solution.second << endl;
      
      for (int j = 0; j < P; ++j) {
	G1.init_alea(G1);
	une_solution = make_pair(G1.eval(), G2.eval());
	fichier << une_solution.first << " " << une_solution.second << endl;
	bool est_domine = false;
	for (auto it = solution_pareto.begin(); ((it != solution_pareto.end())&&(!est_domine)); ++it) {
	  if (((*it).first <= une_solution.first)&&((*it).second <= une_solution.second)) {
	    est_domine = true;
	  }
	  else if ((une_solution.first < (*it).first)&&(une_solution.second < (*it).second)) { 
	    it = solution_pareto.erase(it);
	  }
	}
	if (!est_domine) solution_pareto.push_back(une_solution);
      }
      for (auto it = solution_pareto.begin(); it != solution_pareto.end(); ++it) //Ecriture des solutions pareto dans le fichier
	fichier_pareto << (*it).first << " " << (*it).second << endl;
      
      fichier.close();
      fichier_pareto.close();
     }
     else cerr << "Impossible d'ouvrir l'un des fichier!" << endl;
    }
  return 0;  
}
*/

int main(int argc, char **argv) {
    
						   /* Algorithme de recherche locale */
  srand(time(NULL));
  string fich1 = argv[1];
  fich1.erase(4,1);
  string fich2 = argv[1];
  fich2.erase(3,1);
  string chemin_repertoire_instance = "../data/";
  string nom_fichier1 = chemin_repertoire_instance + fich1 + ".tsp";
  string nom_fichier2 = chemin_repertoire_instance + fich2 + ".tsp";
  
  //Ouverture des deux fichier d'instances en écriture
  ofstream fichier("../resultat/online500_" + (string)argv[1] + ".txt", ios::out | ios::trunc);
  ofstream fichier_pareto("../resultat/onlinePareto500_" + (string)argv[1] + ".txt", ios::out | ios::trunc);

  if (fichier&&fichier_pareto) {
    list<pair <Solution, bool> > A;
    auto it_A = A.begin();
    list<pair <int, int> > voisin_explore;
    auto it_voisin_explore = voisin_explore.begin();
    Graph G1(nom_fichier1);
    Graph G2(nom_fichier2);
    G1.init_alea(G1);
    Solution une_solution(make_pair(G1.eval(), G2.eval()), Graph::configuration);
    A.push_back(make_pair(une_solution, false));
    fichier << une_solution.get_eval().first << " " << une_solution.get_eval().second << endl;
    voisin_explore.push_back(make_pair(0,1));
    bool continu = true;
    Solution x, voisin_x;
    int indice_x;
    while (continu) {
      cout << "Taille de A :" << A.size() << endl;
      continu = false;
      it_voisin_explore = voisin_explore.begin();
      
      // On choisis le premier élément x dans A qui n'est pas marqué
      for (it_A = A.begin(); (it_A != A.end())&&(!continu); ++it_A) {
	++it_voisin_explore;
	if (!(*it_A).second) {
	  x = (*it_A).first;
	  continu = true;
	}
      }
      it_voisin_explore--;
      
      
      if (continu) { // Si il reste au moins un élément de x qui n'est pas marqué alors ...
	bool tmp = true;
	for (int j = (*it_voisin_explore).second; ((j < G1.get_nbCity()) && tmp); ++j) {
	  G1.build_neighbour((*it_voisin_explore).first,j);
	  float G1_eval = G1.eval();
	  float G2_eval = G2.eval();
	  if ((G1_eval < x.get_eval().first) && (G2_eval < x.get_eval().second)) {
	    fichier << G1_eval << " " << G2_eval << endl;
	    tmp = false;
	    voisin_x.set_eval(make_pair(G1_eval, G2_eval));
	    voisin_x.set_configuration(Graph::configuration);
	    (*it_voisin_explore).first = (*it_voisin_explore).first;
	    (*it_voisin_explore).second = j;
	  }
	}
	for (int i = 1 + (*it_voisin_explore).first; ((i < G1.get_nbCity()) && tmp); ++i) {
	  for (int j = i + 1; ((j < G1.get_nbCity()) && tmp); ++j) {
	    G1.build_neighbour(i, j);
	    float G1_eval = G1.eval();
	    float G2_eval = G2.eval();
	    if ((G1_eval < x.get_eval().first) && (G2_eval < x.get_eval().second)) {
	      fichier << G1_eval << " " << G2_eval << endl;
	      tmp = false;
	      voisin_x.set_eval(make_pair(G1_eval, G2_eval));
	      voisin_x.set_configuration(Graph::configuration);
	      (*it_voisin_explore).first = i;
	      (*it_voisin_explore).second = j;
	    }
	  }
	}
	//cout << (*it_voisin_explore).first << " " << (*it_voisin_explore).second << endl;
	if (tmp) (*it_A).second = false; // Si tous les voisins de x ont été exploré alors on marque x à faux 
	else {
	  bool est_domine = false;
	  vector<list<pair <Solution, bool> >::iterator > a_supprimer;
	  for (auto it_tmp = A.begin(); (it_tmp != A.end()) && (!est_domine); ++it_tmp) {
	    if (((*it_tmp).first.get_eval().first <= voisin_x.get_eval().first) && ((*it_tmp).first.get_eval().second <= voisin_x.get_eval().second))
	    est_domine = true;
	    else if ((voisin_x.get_eval().first < (*it_tmp).first.get_eval().first) && (voisin_x.get_eval().second < (*it_tmp).first.get_eval().second)) {
	      a_supprimer.push_back(it_tmp);
	    }
	  }
	  for (int i = 0; i < a_supprimer.size(); ++i) A.erase(a_supprimer[i]);
	  if (!est_domine) {
	    A.push_front(make_pair(voisin_x, false));
	    voisin_explore.push_front(make_pair(0,1));
	  }
	}
      }
    }
    for (it_A = A.begin(); it_A != A.end(); ++it_A) {
      fichier_pareto << (*it_A).first.get_eval().first << " " << (*it_A).first.get_eval().second << endl;
    }
    fichier.close();
    fichier_pareto.close();
  }
  else cerr << "Impossible d'ouvrir l'un des fichier!" << endl;
  
  return 0;
}
