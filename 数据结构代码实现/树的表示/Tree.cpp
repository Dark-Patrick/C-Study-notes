#include<iostream>
#include"Tree.h"
#include"Heap.h"
#include"HUffman.h"
#include<algorithm>
using namespace std;

int main() {
	cout << "\n////////////////////////////测试数据////////////////////////////\n" << endl;

	BinTree(int) BT = new TreeNode<int>(20);
	Insert(21, BT);
	Insert(23, BT);
	Insert(19, BT);
	Insert(10, BT);
	Insert(30, BT);
	Insert(18, BT);
	Insert(26, BT);
	Insert(17, BT);
	PreOrderTraversal(BT);
	cout << "\n------------------------------------" << endl;
	InOrderTraversal(BT);
	cout << "\n------------------------------------" << endl;
	LevelOrderTraversal(BT);
	cout << "\n------------------------------------" << endl;
	cout<<DepthofTree(BT);
	cout << "\n------------------------------------" << endl;

	Delete(30, BT);
	Delete(20, BT);
	PreOrderTraversal(BT);
	cout << "\n------------------------------------" << endl;
	InOrderTraversal(BT);
	cout << "\n------------------------------------" << endl;
	LevelOrderTraversal(BT);
	cout << "\n------------------------------------" << endl;
	cout << DepthofTree(BT);
	cout << "\n------------------------------------" << endl;

	/*MaxHeap(HTreeNode) M = new HeapStruct<HTreeNode>(11);
	
	cout << BulidMinHeap(*M)->Size << endl;;*/

	cout << "\n////////////////////////////测试数据////////////////////////////\n" << endl;

	HeapStruct<int> H(15);
	H.InsertMin(2);
	H.InsertMin(7);
	H.InsertMin(5);
	H.InsertMin(1);
	H.InsertMin(9);
	H.InsertMin(48);
	H.InsertMin(16);
	for (int i = 1; i <= H.Size; i++) {
		cout << H.Elements[i] << "  ";
	}
	cout << "\n------------------------------------" << endl;

	BulidMaxHeap(H);
	for (int i = 1; i <= H.Size; i++) {
		cout << H.Elements[i] << "  ";
	}
	cout << "\n------------------------------------" << endl;

	BulidMinHeap(H);
	for (int i = 1; i <= H.Size; i++) {
		cout << H.Elements[i] << "  ";
	}
	cout << "\n------------------------------------" << endl;
	HeapStruct<HTreeNode> Huff(20);

}