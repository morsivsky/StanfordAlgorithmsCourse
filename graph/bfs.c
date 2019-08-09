#include "graph.c"

void bfs(graphPtr gph,int n,int start)
{
    int* visted =malloc(sizeof(int) * n);
    visted[start] = 1;
    Queue q=initQueue();
    enqueue(q,start);
    printf("%d\n",start);
    while (!emptyQ(q))
    {
        int i =dequeue(q);
        NodePtr curr=gph[i].header;
        while ( curr !=NULL )
        {
            if (visted[curr->data] !=1)
            {
                enqueue(q,curr->data);
                visted[curr->data] = 1;
                printf("%d\n",curr->data);
            }

            curr = curr->next;
        }        
    }
}
