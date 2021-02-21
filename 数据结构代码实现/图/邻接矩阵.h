#pragma once
#include<iostream>
using namespace std;
#define MaxSize 50
#define PtrGNode(T) GNode<T>*
#define PtrENode ENode*
#define MGraph PtrGNode//���ڽӾ��󴢴��ͼ����
#define Edge PtrENode
#define Vertex int
//�޷�װ
template<class T>
struct GNode {
	int Nv;//������

	int Ne;//����

	int G[MaxSize][MaxSize];

	T Data[MaxSize];//��Ŷ��������
};
template<typename T>
MGraph(T) CreateGraph(int VertexNum) {
	Vertex v, w;
	MGraph(T) Graph;

	Graph = (MGraph(T))malloc(sizeof(struct GNode<T>));//c�������ռ䣨NEW��
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (v = 0; v < Graph->Nv; v++)
		for (w = 0; w < Graph->Nv; w++)
			Graph->G[v][w] = 0;//or infinity

	return Graph;
}

//template<class T>
struct ENode {
	Vertex v1, v2;//�����<V1,V2>

	int Weight;//Ȩ��
};
template<typename T>
void InsertEdge(MGraph(T) Graph, Edge E) {
	Graph->G[E->v1][E->v2] = E->Weight;//�����<V1,V2>

	//��Ϊ����ͼ����Ҫ����<V2,V1>
	Graph->G[E->v2][E->v1] = E->Weight;
}
template<typename T>
MGraph(T) BuildGraph() {
	MGraph(T) Graph;
	Edge E;
	//Vertex v;
	int Nv, i;
	cin >> Nv;
	Graph = CreateGraph<T>(Nv);
	cin >> Graph->Ne;
	if (Graph->Ne != 0) {
		E = (Edge)malloc(sizeof(struct ENode));
		for (i = 0; i < Graph->Ne; i++) {
			cin >> E->v1 >> E->v2 >> E->Weight;
			InsertEdge<T>(Graph, E);
		}
	}
	/*for (v = 0; v < Graph->Nv; v++)
		cin >> Graph->Data[v];*/
	//���������ݵĻ�����������

	return Graph;
}