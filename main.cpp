#include<iostream>
#include"graph.h"
#include"doubly_linked_list.h"
using namespace std;
int main()
{
	graph g(6000);
	g.file_reading();
	cout << "\nPrinting graph\n";
	g.printGraph();
	return 0;
}