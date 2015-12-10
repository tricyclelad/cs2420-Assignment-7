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
#include <list>
using namespace std;

struct Node
{
    int nodeID;
    struct Node* next;
    bool visited = false;
    int nodeIcameFrom;
    int startNode;
    int distanceFromStartNode;
    
    void operator =(const Node & rhs)
    {
        nodeID = rhs.nodeID;
        next = rhs.next;
        visited = rhs.visited;
        nodeIcameFrom = rhs.nodeIcameFrom;
        startNode = rhs.startNode;
        distanceFromStartNode = rhs.distanceFromStartNode;
    }
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
            array[i].head = makeNode(i);
    }
   
    Node* makeNode(int ID)
    {
        Node* newNode = new Node;
        newNode->nodeID = ID;
        newNode->next = NULL;
        newNode->nodeIcameFrom = -9;
        newNode->startNode = -9;
        newNode->distanceFromStartNode = -9;
        return newNode;
    }
    
    Node* copyNode(Node *src)
    {
        Node* newNode = new Node;
        newNode->nodeID = src->nodeID;
        newNode->next = src->next;
        newNode->nodeIcameFrom = src->nodeIcameFrom;
        newNode->startNode = src->startNode;
        newNode->distanceFromStartNode = src->distanceFromStartNode;
        return newNode;

    }
    
    void addEdge(int src, int dest)
    {
//        Node* newNode = copyNode(array[dest].head);
//        array[src].head->next = newNode;
       
        Node* newNode = makeNode(dest);
        array[src].head->next = newNode;
//
//        Node* newNode = makeNode(src);
//        newNode->next = array[dest].head;
//        array[dest].head = newNode;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            Node* pCrawl = array[i].head->next;
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
           // cout << "the file " << fileName << " was not found" << endl ;
            fin.close() ;
        }
        else
        {
            //cout << "the file " << fileName << " was found" << endl ;
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
                array[i].head = makeNode(i);
            
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
    
    void breadthFirstSearch(int start)
    {
        // Create a queue for BFS
        list<int> queue;
        int iteratorDistFromStart = 0;
        
        // Mark the current node as visited and enqueue it
        array[start].head->visited = true;
        array[start].head->distanceFromStartNode = iteratorDistFromStart;
        array[start].head->nodeIcameFrom = start;
        array[start].head->startNode = start;

        queue.push_back(start);
        
        iteratorDistFromStart++;
        
        while(!queue.empty())
        {
            // Dequeue a vertex from queue and print it
            int next = queue.front();
            queue.pop_front();
            
            // Get all adjacent vertices of the dequeued vertex s
            // If a adjacent has not been visited, then mark it visited
            // and enqueue it
            Node *temp = array[next].head;
            
            
            while (temp->next != NULL)
            {
                if (!array[next].head->next->visited)
                {
                    array[next].head->next->visited = true;
                    array[next].head->next->startNode = start;
                    array[next].head->next->distanceFromStartNode = iteratorDistFromStart;
                    array[next].head->next->nodeIcameFrom = next;
                    
                    array[temp->next->nodeID].head->visited = true;
                    array[temp->next->nodeID].head->startNode = start;
                    array[temp->next->nodeID].head->distanceFromStartNode = iteratorDistFromStart;
                    array[temp->next->nodeID].head->nodeIcameFrom = next;

                    queue.push_back(temp->next->nodeID);
                    
                }
                temp = temp->next;
                
                
            }
            iteratorDistFromStart++;
        }
        
    }
    
    
    struct shortestCommonAncestor
    {
        int nodeID;
        int whoIcameFromV;
        int whoIcameFromW;
        int length;
    };
    

    shortestCommonAncestor LCA(int v , int w)
    {
        int bestDistanceSoFar = 9999;
        shortestCommonAncestor leastCommonAncestor;
        breadthFirstSearch(v);
        
        // Create a queue for BFS
        list<int> queue;
        int iteratorDistFromStart = 0;
        
        
        // Mark the current node as visited and enqueue it
        array[w].head->visited = true;
        
        if (array[w].head->startNode == v)
        {
            leastCommonAncestor.nodeID = w;
            leastCommonAncestor.whoIcameFromW = w;
            leastCommonAncestor.whoIcameFromV = array[w].head->nodeID;
            leastCommonAncestor.length = array[w].head->distanceFromStartNode;
            return leastCommonAncestor;
        }
        
        array[w].head->distanceFromStartNode = iteratorDistFromStart;
        array[w].head->nodeIcameFrom = w;
        array[w].head->startNode = w;
        
        queue.push_back(w);
        
        iteratorDistFromStart++;
        
        while(!queue.empty())
        {
            // Dequeue a vertex from queue and print it
            int next = queue.front();
           // cout << next << " ";
            queue.pop_front();
            
            // Get all adjacent vertices of the dequeued vertex s
            // If a adjacent has not been visited, then mark it visited
            // and enqueue it
            Node *temp = array[next].head;
            
            
            while (temp->next != NULL)
            {
                if (!array[temp->next->nodeID].head->visited)
                {
                    array[next].head->next->visited = true;
                    array[next].head->next->startNode = w;
                    array[next].head->next->distanceFromStartNode = iteratorDistFromStart;
                    array[next].head->next->nodeIcameFrom = next;
                    
                    array[temp->next->nodeID].head->visited = true;
                    array[temp->next->nodeID].head->startNode = w;
                    array[temp->next->nodeID].head->distanceFromStartNode = iteratorDistFromStart;
                    array[temp->next->nodeID].head->nodeIcameFrom = next;
                    
                    queue.push_back(temp->next->nodeID);
                    
                }   else if(array[temp->next->nodeID].head->startNode == v)
                    {
                        temp->next->distanceFromStartNode = iteratorDistFromStart;
                        
                        int tempDistance = array[temp->next->nodeID].head->distanceFromStartNode + temp->next->distanceFromStartNode;
                        if (tempDistance < bestDistanceSoFar)
                        {
                           
                            leastCommonAncestor.nodeID = array[temp->next->nodeID].head->nodeID;
                            leastCommonAncestor.whoIcameFromV = array[temp->next->nodeID].head->nodeIcameFrom;
                            leastCommonAncestor.whoIcameFromW = temp->nodeID;
                            leastCommonAncestor.length = tempDistance;
                            bestDistanceSoFar = tempDistance;
                        }
                        
                    }
                
               
                temp = temp->next;
                
                
            }
            iteratorDistFromStart++;
        }
        
        
        return leastCommonAncestor;
    }
    
    
    
    void test(int v, int w)
    {
        shortestCommonAncestor leastCommonAncestor = LCA(v, w);
        cout << "LeastCommonAncestor of " << v << " and " << w << " is "<< leastCommonAncestor.nodeID << endl;
        cout << "Length between " << v << " and " << w << " is " << leastCommonAncestor.length << endl;
        
    }
};
#endif
