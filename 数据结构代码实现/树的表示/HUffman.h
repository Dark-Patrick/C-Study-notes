#pragma once
#include<iostream>
#include"Heap.h"
using namespace std;
#define HuffmanTree HTreeNode*
struct HTreeNode {
	int Weight;
	HuffmanTree Left;
	HuffmanTree Right;

	
};
template <class T>
HuffmanTree Huffman(MinHeap(T) H) {
    HuffmanTree HF;
	BulidMinHeap(*H);
	for (int i = 1; i < H->Size; i++) {
		HF = new HTreeNode;
		HF->Left = &H->DeleteMin();
		HF->Right =&H->DeleteMin();
		HF->Weight = HF->Left->Weight + HF->Right->Weight;
		H->InsertMin(*HF);
	}
	HF =& H->DeleteMin();
	return HF;
}
bool operator >(const HTreeNode& H1, const HTreeNode& H2) {
	return H1.Weight > H2.Weight;
}

bool operator <(const HTreeNode& H1, const HTreeNode& H2) {
	return H1.Weight < H2.Weight;
}

