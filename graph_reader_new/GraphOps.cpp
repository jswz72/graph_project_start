#include <unordered_set>
#include <queue>
#include "GraphOps.hpp"

using std::cout;
using std::endl;

// Breadth first search for target in graph
int BFS(graph<long, long, long, long, long, long> *g, int target)
{
    std::queue<int> q;
    int start = g->beg_pos[0];
    q.push(start);
    std::unordered_set<int> visited;
    visited.insert(start);
    int depth = 0;
    int nodes_in_level = 1;
    int nodes_in_next_level = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == target) 
            return depth;
        int beg = g->beg_pos[cur];
        int end = g->beg_pos[cur+1];
        int initQLen = q.size();
        for(int i = beg; i < end; i++)
        {
            int next = g->csr[i];
            if (visited.find(next) == visited.end())
            {
                q.push(next);
                visited.insert(next);
            }
        }
        nodes_in_next_level += q.size() - initQLen;
        nodes_in_level--;
        if (nodes_in_level == 0) {
            depth++;
            nodes_in_level = nodes_in_next_level;
            nodes_in_next_level = 0;
        }
    }
    return -1;
}

