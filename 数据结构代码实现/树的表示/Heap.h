#pragma once
#include<iostream>
#include<cassert>
using namespace std;
#define  MaxHeap(T) HeapStruct<T>*
#define  MinHeap(T) HeapStruct<T>*
//最大堆实现代码c->cpp
template <class T>
class HeapStruct {
public:
	T* Elements;//储存堆元素的数组

	int Size;//堆的当前元素个数

	int Capacity;//堆的最大容量
public:
	HeapStruct(){
		this->Elements = new T[10 + 1];
		this->Size = 0;
		this->Capacity = 10;
		this->Elements[0] = 1E09;
	}
	HeapStruct(int Maxsize) {
		this->Elements = new T[Maxsize + 1];
		this->Size = 0;
		this->Capacity = Maxsize;
		this->Elements[0] = 0x3f3f3f3f;//哨兵结点
	}

	void InsertMax(T item) {//MaxHeap insert
		int i;
		if (this->Size == this->Capacity) {
			cout << "HeapStruct is full" << endl;
			return;
		}
		i = ++(this->Size);
		for (; this->Elements[i / 2] < item; i /= 2)
			this->Elements[i] = this->Elements[i / 2];//从此理解哨兵结点作用
		this->Elements[i] = item;
		return;
	}//T（N）=O(log N)
	void InsertMin(T item) {//MaxHeap insert
		int i;
		if (this->Size == this->Capacity) {
			cout << "HeapStruct is full" << endl;
			return;
		}
		i = ++(this->Size);
		for (; this->Elements[i / 2] > item&&i/2!=0; i /= 2)
			this->Elements[i] = this->Elements[i / 2];
		this->Elements[i] = item;
		return;
	}
	
	T DeleteMax() {
		int parent, child;
		T MaxItem, temp;
		if (this->Size == 0) {
			cout << "HeapStruct is empty" << endl;
			return ;
		}
		MaxItem = this->Elements[1];
		temp = this->Elements[this->Size--];
		for (parent = 1; parent * 2 <= this->Size; parent = child) {
			child = parent * 2;
			if (child != this->Size && (this->Elements[child] < this->Elements[child + 1]))
				child++;
			if (temp > this->Elements[child])break;//此时父节点的child结点都比temp小，退出循环
			                                       //并将temp赋给parent
			else//移动temp元素到下一层
				this->Elements[parent] = this->Elements[child];
		}
		this->Elements[parent] = temp;
		return MaxItem;

		//利用此函数可直接建最大堆，倒序调整
	}

	T DeleteMin() {
		int parent, child;
		T MinItem, temp;
		if (this->Size == 0) {
			cout << "HeapStruct is empty" << endl;
			return;
		}
		MinItem = this->Elements[1];
		temp = this->Elements[this->Size--];
		for (parent = 1; parent * 2 <= this->Size; parent = child) {
			child = parent * 2;
			if (child != this->Size && (this->Elements[child] > this->Elements[child + 1]))
				child++;
			if (temp < this->Elements[child]) break;

			else
				this->Elements[parent] = this->Elements[child];
		}
		this->Elements[parent] = temp;
		return MinItem;
	}

	

};

template<class T>
MaxHeap(T) BulidMaxHeap(HeapStruct<T>& H) {

	int parent, child;
	T  temp;
	if (H.Size == 0) {
		cout << "HeapStruct is empty" << endl;
		return &H;
	}
	parent = (H.Size) / 2;
	for (int i = H.Size / 2; i >= 1; i--) {
		parent = i;
        temp = H.Elements[parent];
		for (; parent*2<H.Size; parent=child) {
			child = parent * 2;
			if (child + 1 <= H.Size && H.Elements[child] < H.Elements[child + 1])
				child++;
			
			if (temp > H.Elements[child]) break;

			else
				H.Elements[parent] = H.Elements[child];
		}
		H.Elements[parent] = temp;
    }
	return &H;
}
template<class T>
MinHeap(T) BulidMinHeap(HeapStruct<T> &H) {

	int parent, child;
	T  temp;
	if (H.Size == 0) {
		cout << "HeapStruct is empty" << endl;
		return &H;
	}
	parent = (H.Size) / 2;
	for (int i = H.Size / 2; i >= 1; i--) {
		parent = i;
		temp = H.Elements[parent];
		for (; parent * 2 < H.Size; parent = child) {
			child = parent * 2;
			if (child + 1 <= H.Size && H.Elements[child] > H.Elements[child + 1])
				child++;

			if (temp < H.Elements[child]) break;

			else
				H.Elements[parent] = H.Elements[child];
		}
		H.Elements[parent] = temp;
	}
	return &H;
}