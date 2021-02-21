#pragma once
#ifndef ARRAY_H
#define ARRAY_H
#include<cassert>
template<class T>//������ģ�嶨��
class Array {
	T* list;//���ڴ�Ŷ�̬����������ڴ��׵�ַ
	int size;//�����С��Ԫ�ظ�����
public:
	Array(int sz = 50) {
		assert(sz >= 0);//szΪ�����С��Ԫ�ظ�������Ӧ���Ǹ�
		size = sz;
		list = new T[size];//��̬����size��T���͵�Ԫ�ؿռ�
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
	Array<T>& operator =(const Array<T>& rhs);//����=
	T& operator [](int);//����[]������
	operator T* ();//���ص�T*���͵�ת��
	operator const T* ()const;
	int getSize()const;
	void resize(int sz);
};
//����ʵ��
template<class T>
Array<T>& Array<T>::operator=(const Array<T>& rhs) {
	if (&rhs != this) {
//����������������С��rhs��ͬ����ɾ������ԭ���ڴ棬���·���
		if (size != rhs.size) {
			delete[]list;
			size = rhs.size;
			list = new T[size];
		}
		for (int i = 0; i < size; i++)
			list[i] = rhs.list[i];
	}
	return *this;//���ص�ǰ���������
}


template<class T>
T& Array<T>::operator[](int n) {
	assert(n >= 0 && n <= size);//����±��Ƿ�Խ��
	return list[n];//��������T& �Ƿ���ֵΪ��ֵ����������Ԫ�أ���ȡ�ҿ��Ըı�
}
/*
template<class T>
const T& Array<T>::operator[](int n)const {
	assert(n >= 0 && n <= size);
	return list[n];
	�����ã�ֻ�����Ͳ��ܸı�Ԫ�ص�ֵ
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
	delete[]list;//ɾ��ԭ����
	list = newList;//ʹlistָ���µ�����
	size = sz;
}



#endif