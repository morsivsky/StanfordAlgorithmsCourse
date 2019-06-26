#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}Node,*NodePtr;

typedef struct Graph
{
	NodePtr head;
} graph,*graphPtr;
NodePtr makeNode(int data)
{
	NodePtr node = (NodePtr)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}
void AddAtFirst(NodePtr *head, int data)
{
	NodePtr newHead = makeNode(data);
	newHead->next = *head;
	*head = newHead;
}

void DisplayLinkedList(NodePtr node)
{
	NodePtr current = node;
	while (current != NULL)
	{
		printf("%d ->", current->data);
		current = current->next;
	}
}


void buildGraph(int m ,graphPtr graph)
{
	for (int i = 0; i < m; i++)
	{
		int v1, v2;
		scanf("%d %d",& v1, &v2);
		if (graph[v1].head == NULL)
			graph[v1].head = makeNode(v2);
		else
			AddAtFirst(&graph[v1].head, v2);

		if (graph[v2].head ==NULL)
			graph[v2].head = makeNode(v1);
		else
			AddAtFirst(&graph[v2].head, v1);
	}
}

void printGraph(graphPtr gra, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ---->", i);
		DisplayLinkedList(gra[i].head);
		printf("\n");
	}
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
