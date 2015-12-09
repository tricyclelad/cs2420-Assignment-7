//
//  Graph.h
//  CS2420 Assignment 7 Graphs
//
//  Created by Camron Blake Martinez on 12/8/15.
//  Copyright © 2015 Camron Blake Martinez. All rights reserved.
//

#ifndef Graph_h
#define Graph_h
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct Node
{
    int nodeID;
    struct Node* next;
    
};

/*
 * Adjacency List
 */
struct AdjList
{
    struct Node *head;
};

/*
 * Class Graph
 */
class Graph
{
private:
    int size;
   // struct AdjList* array;
    vector<AdjList> array;
public:
    
    Graph()
    {
        this->size = 0;
    }
    
    Graph(int size)
    {
        this->size = size;
        //array = new AdjList [size];
        array.resize(size);
        for (int i = 0; i < size; ++i)
            array[i].head = NULL;
    }
   
    Node* makeNode(int ID)
    {
        Node* newNode = new Node;
        newNode->nodeID = ID;
        newNode->next = NULL;
        return newNode;
    }
    
    void addEdge(int src, int dest)
    {
        Node* newNode = makeNode(dest);
        newNode->next = array[src].head;
        array[src].head = newNode;
        
//        Node* newNode = makeNode(src);
//        newNode->next = array[dest].head;
//        array[dest].head = newNode;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            Node* pCrawl = array[i].head;
            cout<<"\n Node "<< i <<"\n";
            while (pCrawl)
            {
                cout<<"-> "<<pCrawl->nodeID;
                pCrawl = pCrawl->next;
            }
            cout<<endl;
        }
    }
    
    void buildGraph(string fileName)
    {
        ifstream fin;
            
        fin.open(fileName);
            
        if (fin.fail())   // callling the member function to verify
        {
            cout << "the file " << fileName << " was not found" << endl ;
            fin.close() ;
        }
        else
        {
            cout << "the file " << fileName << " was found" << endl ;
            char fileWord[80];
            //string fileWord = " ";
            
            /*
                while(!fin.eof())
                {
                fin.getline(info, 80);
                cout << info << endl ;
                }
            */
            
            //Get the number of nodes
            fin.getline(fileWord, 80);
            stringstream ss(fileWord);
            int nodeSize;
            ss >> nodeSize;
            ss.clear();
            
            //Resize the graph and "initialize" it to null
            this->size = nodeSize;
            array.resize(size);
            for (int i = 0; i < size; i++)
                array[i].head = NULL;
            
            int edgeCount;
            fin.getline(fileWord, 80);
            
            ss.str(fileWord);
            ss >> edgeCount;
            ss.clear();
            
            int source;
            int dest;
            
            while (fin.getline(fileWord, 80))
            {
             // cout << fileWord << endl;
                ss.str(fileWord);
                ss >> source >> dest;
                addEdge(source, dest);
                ss.clear();
            }
        }
        fin.close() ; // close the file handler once the operations are done
    }
    
};
#endif
