#include<iostream>
#include"graph.h"
#include"doubly_linked_list.h"
using namespace std;
int main()
{
	graph g(6000);
	g.file_reading();
	//g.printGraph();
	cout<<"\nBiggest social circle of person "<<g.biggest_social_circle()<<endl;
	g.common_profiles(2001, 2002);
	g.add_nodes_edges();
	return 0;
}