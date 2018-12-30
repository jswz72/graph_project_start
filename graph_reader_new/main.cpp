#include <iostream>
#include "GraphOps.hpp"
#include "graph.h"

int main(int args, char **argv)
{
	std::cout<<"Input: ./exe beg csr weight target\n";
	if(args!=5){std::cout<<"Wrong input\n"; return -1;}
	
	const char *beg_file=argv[1];
	const char *csr_file=argv[2];
	const char *weight_file=argv[3];
	const int target = atoi(argv[4]);
	
	//template <file_vertex_t, file_index_t, file_weight_t
	//new_vertex_t, new_index_t, new_weight_t>
	graph<long, long, /*int*/long, long, long,/* char*/long>
	*ginst = new graph
	<long, long, /*int*/long, long, long, /*char*/long>
	(beg_file,csr_file,weight_file);
    
	int result = GraphOps::BFS(ginst, target);
	if (result < 0) std::cout << target << " not found in graph" << std::endl;
	else std::cout << target << " found at depth " << result << std::endl;


	return 0;	
}
