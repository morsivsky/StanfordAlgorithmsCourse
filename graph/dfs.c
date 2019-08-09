#include "graph.c"

void dfs(graphPtr gph,int start, int* visited)
{
    visited[start] = 1;
    NodePtr nd = gph[start].header;
    printf("%d\n",start);
    while (nd !=NULL)
    {
        if (visited[nd->data] !=1)
        {
            dfs(gph,nd->data,visited);
        }
        nd = nd->next;
    }
}