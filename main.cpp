#include <iostream>

#include "graphe.h"
#include "loader.h"

using namespace std;


int main(int argc, char **argv) {
    Graph G("/home/etudiant/data-OptiC/kroA100.tsp");
    
    cout << G << endl;
    
    return 0;
}
