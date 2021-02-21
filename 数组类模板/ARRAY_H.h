#pragma once
#ifndef ARRAY_H
#define ARRAY_H
#include<cassert>
template<class T>//数组类模板定义
class Array {
	T* list;//用于存放动态分配的数组内存首地址
	int size;//数组大小（元素个数）
public:
	Array(int sz = 50) {
		assert(sz >= 0);//sz为数组大小（元素个数）。应当非负
		size = sz;
		list = new T[size];//动态分配size个T类型的元素空间
	};
	Array(const Array<T>& a) {
		size = a.size;
		list = new T[size];
		for (int i = 0; i < size; i++)
			list[i] = a.list[i];
	}
	~Array() {
		delete[] list;
	}
	Array<T>& operator =(const Array<T>& rhs);//重载=
	T& operator [](int);//重载[]常函数
	operator T* ();//重载到T*类型的转换
	operator const T* ()const;
	int getSize()const;
	void resize(int sz);
};
//函数实现
template<class T>
Array<T>& Array<T>::operator=(const Array<T>& rhs) {
	if (&rhs != this) {
//如果本对象中数组大小与rhs不同，则删除数组原有内存，重新分配
		if (size != rhs.size) {
			delete[]list;
			size = rhs.size;
			list = new T[size];
		}
		for (int i = 0; i < size; i++)
			list[i] = rhs.list[i];
	}
	return *this;//返回当前对象的引用
}


template<class T>
T& Array<T>::operator[](int n) {
	assert(n >= 0 && n <= size);//检查下标是否越界
	return list[n];//返回引用T& 是返回值为左值，访问数组元素，读取且可以改变
}
/*
template<class T>
const T& Array<T>::operator[](int n)const {
	assert(n >= 0 && n <= size);
	return list[n];
	常引用，只读，就不能改变元素的值
*/

template<class T>
Array<T>::operator T* () {
	return list;
}
template<class T>
Array<T>::operator const T* ()const {
	return list;
}


template<class T>
int Array<T>::getSize()const {
	return size;
}



template<class T>
void Array<T>::resize(int sz) {
	assert(sz > +0);
	if (sz == size)
		return;
	T* newList = new T[sz];
	int n = (sz < size) ? sz : size;
	for (int i = 0; i < n; i++)
		newList[i] = list[i];
	delete[]list;//删除原数组
	list = newList;//使list指向新的数组
	size = sz;
}



#endif