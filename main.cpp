#include <iostream>

#include "graphe.h"
#include "loader.h"

using namespace std;


int main(int argc, char **argv) {
    srand(time(NULL));
    Graph G("/home/etudiant/Bureau/data/kroA100.tsp");
    G.init(G);
    //G.init_alea(G);
    cout << "Evaluation de la solution : " << G.eval() << endl;
   /*for (int i = 0; i < G.get_nbCity(); ++i) {
      cout << endl;
     for(int j = 0; j < G.get_nbCity(); ++j) {
       cout << G.get_distances()[i][j] << " ";
     }
    }*/
    return 0;
}
