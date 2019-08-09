#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node,*NodePtr;

typedef struct graph
{
    NodePtr* header;
}Graph,*graphPtr;

typedef struct queueType{
    NodePtr head;
    NodePtr tail;
} QueueType, *Queue;

typedef enum bool
{
    false=0,
    true=1
} bool;


NodePtr newNode(int data)
{
    NodePtr node= malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    return node;
}

void addFirst(NodePtr *header,int data)
{
    NodePtr node = newNode(data);
    node->next = *header;
    *header = node;
}

void addEdge(int v1,int v2,graphPtr graph)
{
    if (graph[v1].header == NULL)
    {
        graph[v1].header = newNode(v2);
    }
    else
    {
        addFirst(&graph[v1].header,v2);
    }
    
    if (graph[v2].header == NULL)
    {
        graph[v2].header = newNode(v1);
    }
    else
    {
        addFirst(&graph[v2].header,v1);
    }
    

}
void printList(NodePtr header)
{
    NodePtr currentNode= header;
    while (currentNode !=NULL)
    {
        printf("%d -> ",currentNode->data);
        currentNode = currentNode->next;
    }
    
}
//m
void buildGraph(int m,int n,graphPtr *graph)
{
    for (int i = 0; i < m; i++)
    {
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        addEdge(v1,v2,graph);
    }    
}

void printGaraph(int n,graphPtr graph)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d : ",i);
        printList(graph[i].header);
        printf("\n");
    }
}

Queue initQueue(){
	Queue qp = (Queue) malloc(sizeof(QueueType));
	qp->head = NULL;
	qp->tail = NULL;
    return qp;
}

bool emptyQ(Queue q){
	return (q->head == NULL);
}

// Add to queue
void enqueue(Queue q, int x){ // Insert back
    NodePtr np =  newNode(x);
    if(emptyQ(q)){
        q->head = np;
        q->tail = np;
        return;
    }
    q ->tail->next = np;
    q->tail = np;
}

// Remove from queue
int dequeue(Queue q){ // Delete front
    if(emptyQ(q)){
		printf("\nQueue is empty!\n");
		return -1;
    }
    NodePtr p = q->head;
    int x = p->data;
    q->head = q->head->next;
    if(q->head == NULL)
        q->tail = NULL;
    free(p);
    return x;
}

/*

int main() {
    int m, n;
	scanf("%d %d", &n, &m);
	graphPtr gra= calloc(n, sizeof(graphPtr));
	graphPtr test0 = &gra[1];
	graphPtr test = &gra[2];
	buildGraph(m, gra);
	printGraph(gra, n);
	return 0;
}*/
