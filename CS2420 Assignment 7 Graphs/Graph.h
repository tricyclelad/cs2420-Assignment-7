//
//  Graph.h
//  CS2420 Assignment 7 Graphs
//
//  Created by Camron Blake Martinez on 12/8/15.
//  Copyright © 2015 Camron Blake Martinez. All rights reserved.
//

#ifndef Graph_h
#define Graph_h
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;

class Edge
{
public:
    int toNode;
    int fromNode;
    Edge *next; //Next edge in the list
    
    Edge(int from = -1, int to = -1, Edge *nextEdge = NULL){
        toNode=to;
        fromNode=from;
        next = nextEdge;
    }
};
class Node
{
public:
    int nodeID;
    Edge *adjList; //Adjacency List
    bool visited;
    Node *whoIcameFrom;
    int distanceFromTarget;
    
    Node(int id = -1, Edge *List = NULL)
    {
        nodeID=id;
        adjList = List;
        visited=false;
        whoIcameFrom = NULL;
        distanceFromTarget=0;
    }
};


class Graph
{
protected:
    Node *G;
    int nodeCt;
public:
    Graph(int size) { G = new Node[size]; nodeCt = size;};
    
    
    void BuildGraph(istream & input);
};

private:
//    int V;
//    struct AdjList* array;
//public:
//    Graph(int V)
//    {
//        this->V = V;
//        array = new AdjList [V];
//        for (int i = 0; i < V; ++i)
//            array[i].head = NULL;
//    }
//    /*
//     * Creating New Adjacency List Node
//     */
//    AdjListNode* newAdjListNode(int dest)
//    {
//        AdjListNode* newNode = new AdjListNode;
//        newNode->dest = dest;
//        newNode->next = NULL;
//        return newNode;
//    }
//    /*
//     * Adding Edge to Graph
//     */
//    void addEdge(int src, int dest)
//    {
//        AdjListNode* newNode = newAdjListNode(dest);
//        newNode->next = array[src].head;
//        array[src].head = newNode;
//        newNode = newAdjListNode(src);
//        newNode->next = array[dest].head;
//        array[dest].head = newNode;
//    }
//    /*
//     * Print the graph
//     */
//    void printGraph()
//    {
//        int v;
//        for (v = 0; v < V; ++v)
//        {
//            AdjListNode* pCrawl = array[v].head;
//            cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
//            while (pCrawl)
//            {
//                cout<<"-> "<<pCrawl->dest;
//                pCrawl = pCrawl->next;
//            }
//            cout<<endl;
//        }
//    }


#endif /* Graph_h */





///*
// * C++ Program to Implement Adjacency List
// */
//#include <iostream>
//#include <cstdlib>
//using namespace std;
//
///*
// * Adjacency List Node
// */
//struct AdjListNode
//{
//    int dest;
//    struct AdjListNode* next;
//};
//
///*
// * Adjacency List
// */
//struct AdjList
//{
//    struct AdjListNode *head;
//};
//
///*
// * Class Graph
// */
//class Graph
//{
//private:
//    int V;
//    struct AdjList* array;
//public:
//    Graph(int V)
//    {
//        this->V = V;
//        array = new AdjList [V];
//        for (int i = 0; i < V; ++i)
//            array[i].head = NULL;
//    }
//    /*
//     * Creating New Adjacency List Node
//     */
//    AdjListNode* newAdjListNode(int dest)
//    {
//        AdjListNode* newNode = new AdjListNode;
//        newNode->dest = dest;
//        newNode->next = NULL;
//        return newNode;
//    }
//    /*
//     * Adding Edge to Graph
//     */
//    void addEdge(int src, int dest)
//    {
//        AdjListNode* newNode = newAdjListNode(dest);
//        newNode->next = array[src].head;
//        array[src].head = newNode;
//        newNode = newAdjListNode(src);
//        newNode->next = array[dest].head;
//        array[dest].head = newNode;
//    }
//    /*
//     * Print the graph
//     */
//    void printGraph()
//    {
//        int v;
//        for (v = 0; v < V; ++v)
//        {
//            AdjListNode* pCrawl = array[v].head;
//            cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
//            while (pCrawl)
//            {
//                cout<<"-> "<<pCrawl->dest;
//                pCrawl = pCrawl->next;
//            }
//            cout<<endl;
//        }
//    }
//};
