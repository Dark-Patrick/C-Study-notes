#pragma once
#include<iostream>
#include"�ڽӾ���.h"
using namespace std;
#define Vertex int
#define MaxVertexNum 50
#define PtrToGNode GNodeptr*
#define LGraph PtrToGNode
#define PtrToAdjVNode AdjVNode*

//�ڽӱ�G[n]Ϊָ�����飬��Ӧ����ÿ��һ������ֻ�����Ԫ��

struct GNodeptr {
	int Nv;
	int Ne;
	AdjList G;//�ڽӱ�
};

typedef struct Vnode {
	PtrToAdjVNode FirstEdge;

	int Data;
}AdjList[MaxVertexNum];//AdjList���ڽӱ�����

struct AdjVNode {
	Vertex Adjv;//�ڽӵ��±�

	int Weight;//��Ȩ��

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
	//�����<V1,V2>
	//ΪV2�����µ��ڽӵ�
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->Adjv = E->v2;
	NewNode->Weight = E->Weight;
	//��V2����V1��ͷ
	NewNode->Next = Graph->G[E->v1].FirstEdge;
	Graph->G[E->v1].FirstEdge = NewNode;

	//��Ϊ����ͼ���ٲ����<V2,V1>
	//ΪV1�����µ��ڽӵ�
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->Adjv = E->v1;
	NewNode->Weight = E->Weight;
	//��V1����V2��ͷ
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