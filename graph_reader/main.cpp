#include <iostream>
#include <queue>
#include <unordered_set>
#include "graph.h"

using std::endl;

// Breadth first search for target in graph
void BFS(graph<long, long, int, long, long, char> *g, int target)
{
    std::queue<int> q;
    q.push(0);
    std::unordered_set<int> visited;
    visited.insert(0);
    int depth = 0;
    int nodes_in_level = 1;
    int nodes_in_next_level = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == target) 
        {
            std::cout << "Found " << target << " at level: " << depth << endl;
            return;
        }
        int beg = g->beg_pos[cur];
        int end = g->beg_pos[cur+1];
        int to_add = 0;
        for(int i = beg; i < end; i++)
        {
            int next = g->csr[i];
            if (visited.find(next) == visited.end())
            {
                to_add++;
                q.push(next);
                visited.insert(next);
            }
        }
        nodes_in_next_level += to_add;
        nodes_in_level--;
        if (nodes_in_level == 0) {
            depth++;
            nodes_in_level = nodes_in_next_level;
            nodes_in_next_level = 0;
        }
    }
}

int main(int args, char **argv)
{
	std::cout<<"Input: ./exe beg csr weight element\n";
	if(args!=5){std::cout<<"Wrong input\n"; return -1;}
	
	const char *beg_file=argv[1];
	const char *csr_file=argv[2];
	const char *weight_file=argv[3];
    const int target = atoi(argv[4]);
	
	//template <file_vertex_t, file_index_t, file_weight_t
	//new_vertex_t, new_index_t, new_weight_t>
	graph<long, long, int, long, long, char>
	*ginst = new graph
	<long, long, int, long, long, char>
	(beg_file,csr_file,weight_file);

    BFS(ginst, target);
	return 0;	
}

