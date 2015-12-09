//
//  main.cpp
//  CS2420 Assignment 7 Graphs
//
//  Created by Camron Blake Martinez on 12/8/15.
//  Copyright © 2015 Camron Blake Martinez. All rights reserved.
//

#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
    
//    Graph gh(5);
//    gh.addEdge(0, 1);
//    gh.addEdge(0, 4);
//    gh.addEdge(1, 2);
//    gh.addEdge(1, 3);
//    gh.addEdge(1, 4);
//    gh.addEdge(2, 3);
//    gh.addEdge(3, 4);
    

//    gh.print();
//
    
    
    Graph g;
    g.buildGraph("digraph1.txt");
    g.print();
    return 0;
}
