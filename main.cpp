#include<iostream>
#include"graph.h"
using namespace std;

 linked_list <NODE*>  nodes;
 linked_list <EDGE*>  edges;

int main()
{
	graph g(6000);
	g.file_reading();
	//g.printGraph();
	cout<<"\nBiggest social circle of person "<<g.biggest_social_circle()<<endl;
	g.common_profiles(2001, 2002);
	g.add_nodes_edges();
	g.calculate_social_distance_between_profiles(2400 ,2300);
	return 0;
}