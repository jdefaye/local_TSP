#include <iostream>

#include "graphe.h"
#include "loader.h"
#include <list>

#define P 500

using namespace std;





int main(int argc, char **argv) {
    srand(time(NULL));
    string chemin_repertoire_instance = "/home/etudiant/Bureau/data/";
    string tableau_instances[7] = {"kroAB100", "kroBC100", "kroCD100", "kroDE100", "kroAE100", "kroAB150", "kroAB200"};
    pair<string, string> tableau_fichier_instances[7] = {make_pair("kroA100.tsp", "kroB100.tsp"),make_pair("kroB100.tsp", "kroC100.tsp"),make_pair("kroC100.tsp", "kroD100.tsp"),make_pair("kroD100.tsp", "kroE100.tsp"),make_pair("kroA100.tsp", "kroE100.tsp"),make_pair("kroA150.tsp", "kroB150.tsp"),make_pair("kroA200.tsp", "kroB200.tsp")};
    for (int i = 0; i < 7; ++i) {
     vector<pair<float, float > > ensemble_solution;
     list<pair<float, float> > solution_pareto;
     ensemble_solution.resize(P);
     string nom_fichier1 = chemin_repertoire_instance + tableau_fichier_instances[i].first;
     string nom_fichier2 = chemin_repertoire_instance + tableau_fichier_instances[i].second;
     ofstream fichier("../resultat/offline500_" + tableau_instances[i] + ".txt", ios::out | ios::trunc);
     ofstream fichier_pareto("../resultat/offlinePareto500_" + tableau_instances[i] + ".txt", ios::out | ios::trunc);
     if (fichier&&fichier_pareto) {
      Graph G1(nom_fichier1);
      Graph G2(nom_fichier2);
      /*
      //offline
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
      }*/
      //online
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
      for (auto it = solution_pareto.begin(); it != solution_pareto.end(); ++it)
	fichier_pareto << (*it).first << " " << (*it).second << endl;
      
      fichier.close();
      fichier_pareto.close();
     }
     else cerr << "Impossible d'ouvrir l'un des fichier!" << endl;
    }
    return 0;
}
