#pragma once
#include<iostream>
#include"邻接矩阵.h"
using namespace std;
#define Vertex int
#define MaxVertexNum 50
#define PtrToGNode GNodeptr*
#define LGraph PtrToGNode
#define PtrToAdjVNode AdjVNode*

//邻接表：G[n]为指针数组，对应矩阵每行一个链表，只存非零元素

struct GNodeptr {
	int Nv;
	int Ne;
	AdjList G;//邻接表
};

typedef struct Vnode {
	PtrToAdjVNode FirstEdge;

	int Data;
}AdjList[MaxVertexNum];//AdjList是邻接表类型

struct AdjVNode {
	Vertex Adjv;//邻接点下标

	int Weight;//边权重

	PtrToAdjVNode Next;
};
LGraph CreateLGraph(int VertexNum) {
	Vertex v;
	LGraph Graph;

	Graph = (LGraph)malloc(sizeof(struct GNodeptr));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (v = 0; v < Graph->Nv; v++)
		Graph->G[v].FirstEdge = NULL;

	return Graph;
}
void InsertEdge(LGraph Graph, Edge E) {
	PtrToAdjVNode NewNode;
	//插入边<V1,V2>
	//为V2建立新的邻接点
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->Adjv = E->v2;
	NewNode->Weight = E->Weight;
	//将V2插入V1表头
	NewNode->Next = Graph->G[E->v1].FirstEdge;
	Graph->G[E->v1].FirstEdge = NewNode;

	//若为无向图，再插入边<V2,V1>
	//为V1建立新的邻接点
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->Adjv = E->v1;
	NewNode->Weight = E->Weight;
	//将V1插入V2表头
	NewNode->Next = Graph->G[E->v2].FirstEdge;
	Graph->G[E->v2].FirstEdge = NewNode;
}

LGraph BuildLGraph() {
	LGraph Graph;
	Edge E;
	Vertex v;
	int Nv, i;
	cin >> Nv;
	Graph = CreateLGraph(Nv);
	cin >> Graph->Ne;
	if (Graph->Ne != 0) {
		E = (Edge)malloc(sizeof(struct ENode));
		for (i = 0; i < Graph->Ne; i++) {
			cin >> E->v1 >> E->v2 >> E->Weight;
			InsertEdge(Graph, E);
		}
	}
	/*for (v = 0; v < Graph->Nv; v++) {
		cin >> Graph->G[v].Data;
	}*/
	return Graph;
}