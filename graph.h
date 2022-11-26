#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "doubly_linked_list.h"
#include"Node.h"
#include"Edge.h"
#include"PATH_GRAPH.h"
using namespace std;

class graph {
   private:
    linked_list <int> *list;
    int Vertices;

   public:
    graph() {
        Vertices = 0;
        list = NULL;
    }
    graph(int vertices) {
        Vertices = vertices;
        list = new linked_list<int>[vertices];
    }

    void add_edge(int i, int j) 
    {
        list[i].insert(j);  // i is friend of j
        list[j].insert(i);  // j is friend of i
    }

    //returns person with biggest social circle
    int biggest_social_circle()
    {
        int i = 0;
        int j = 0;
        int max = 0;
        int id_max = 0;
        for (i = 0; i < Vertices; i++)
        {
            for (j = 0; j < list[i].get_size(); ++j)
            {
                if (list[i].get_size() > max)
                {
                    max = list[i].get_size();
                    id_max = i;
                }
            }
            cout << endl;
        }
        return id_max;
    }


    //Two people with common profiles
    void common_profiles(int i, int j)
    {
        linked_list <int> list_common;
        cout << "\nCommon Profiles\n";
        for (int k = 0; k < list[i].get_size(); k++)
        {
            for (int l = 0; l < list[j].get_size(); l++)
            {
                if (list[i][k] == list[j][l])
                {
                    if (list_common.get_size() == 0)
                    {
                        list_common.insert(list[i][k]);
                    }
                    else if (!list_common.search(list[i][k]))
                    {
                          list_common.insert(list[i][k]);
                    }
                }
            }
        }
            list_common.display();
    }


    void printGraph() 
    {
        cout << "\nSocial circles\n";
        int i = 0;
        int j = 0;
        for (i = 0; i < Vertices; i++) 
        {
            for (j = 0; j < list[i].get_size(); ++j) 
            {
                cout << list[i][j]<<" ";  // overloaded
            }
            cout << endl;
        }
        cout << endl;
    }
    

    void add_nodes_edges()
    {
        linked_list <NODE*> graph_node;
        linked_list <EDGE*> graph_edge;

        for (int i = 0; i < Vertices; i++)
        {
            NODE* temp = new NODE(i);
            graph_node.insert(temp);
            
        }
        for (int j = 0; j < Vertices; j++)
        {
            NODE* node_1 = graph_node[j];
            for (int k = 0; k < list[j].get_size(); k++)
            {
                NODE* node_2 = graph_node[list[j][k]];
                EDGE* edge = new EDGE(node_1 , node_2);
            }
        }

        //printing graph

        for (int i = 0; i < graph_node.get_size(); i++)
        {
            cout << graph_node[i]->id<<" ";
        }

        for (int i = 0; i < graph_edge.get_size(); i++)
        {
            cout <<"\nDistance :"<< graph_edge[i]->node_1->id << " ";
            cout << "\nNode 1 :" << graph_edge[i]->node_2->id << " ";
            cout << "\nNode 2 :" << graph_edge[i]->dist << " ";
        }
    }

    
    void file_reading() 
    {
        fstream myfile;
        myfile.open("friends.txt", ios::in);
        string num;
        string first_node = "";
        bool f_node = false;
        string other_nodes = "";
        while (getline(myfile, num)) 
        {
            for (int i = 0; i < num.size(); i++) 
            {
                if (num[i] != ' ') 
                {
                    if (f_node == false && num[i] !=' ')  // first node has come and turn it to true
                    {
                        for (int j = 0; num[j] != ':'; j++, i++)  // add into first node string until :
                                        // arrives
                        {
                            first_node += num[j];
                        }

                        f_node = true;  // first node has passed
                       // cout << "\n " << first_node << ": ";
                    }

                    else if (num[i] != ' ')  // other nodes
                    {
                        for (int j = i; num[j] != ' '; j++,  i++)  // add into string until next space comes
                        {
                            other_nodes += num[j];
                        }

                       // cout << "" << other_nodes << " ";

                        // now here add first and other node to the add edge
                        // function
                        add_edge(stoi(first_node), stoi(other_nodes));

                        // emptying both strings
                        other_nodes = "";
                    }
                }
            }
            f_node = false;
            first_node = "";
        }
        myfile.close();
    }

   

};