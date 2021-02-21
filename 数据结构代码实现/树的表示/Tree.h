#pragma once
#include<iostream>
#include<stack>
#include<deque>
using namespace std;

#define BinTree(T) TreeNode<T>*
#define Position BinTree(T)
//������
template <class T>
class TreeNode {
public:
	T Data;
	BinTree(T) Left;
	BinTree(T) Right;
	int flag = 0;
public:
	TreeNode() {}
	TreeNode(T D, BinTree(T) l = NULL, BinTree(T) r = NULL) :Data(D) {
		this->Left = l;
		this->Right = r;
	}
};

//�����������������⣺��ά�ṹ�����Ի�
//�ݹ鷽ʽʵ��
//�������
template <class T>
void PreOrderTraversal(BinTree(T) BT) {
	if (BT) {
		cout << BT->Data << "  ";
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
	}
}
//�������
template <class T>
void PreOrderTraversal2(BinTree(T) BT) {
	if (BT) {
		PreOrderTraversal2(BT->Left);
		cout << BT->Data << " ";
		PreOrderTraversal2(BT->Right);
	}
}
//�������
template <class T>
void PreOrderTraversal3(BinTree(T) BT) {
	if (BT) {
		PreOrderTraversal3(BT->Left);
		PreOrderTraversal3(BT->Right);
		cout << BT->Data << " ";
	}
}
//�������򣬺�����������о����ڵ�ĵ�·��һ�£��������ڷ��ʸ��ڵ��ʱ����ͬ
//��������ʵ�֣���ͼ�ҹ���

//�������,���ú������
template <class T>
int DepthofTree(BinTree(T) BT) {
	int L, R, max;
	if (BT) {
		L= DepthofTree(BT->Left);
		R= DepthofTree(BT->Right);
		max = (L >= R) ? L : R;
		return (max + 1);
	}
	else return 0;
}

//�ǵݹ������ֱ�Ӷ�ջʵ��
//��������ǵݹ�����㷨
template <class T>
void InOrderTraversal(BinTree(T) BT) {
	BinTree(T) B = BT;
	stack<BinTree(T)> s;
	while (B || !s.empty()) {
		while (B) {
			//cout << B->Data << "  ";  //�ڴ�������ݣ���Ϊ�������
			s.push(B);

			/*if (B->Left == NULL) {
				B = B->Right;
				s.push(B);
			}*/ //��������㷨ʵ�֣���ȫ��if (!s.empty()) �������޸�

			B = B->Left;
		}
		if (!s.empty()) {
			B = s.top();//����ջ��Ԫ�ص�����
			s.pop();//����void
			cout << B->Data << "  ";
			B = B->Right;
		}
	}
}

//�������
//����ʵ�֣������Ӹ��ڵ㿪ʼ���Ƚ�root��ӣ���ʼִ��ѭ����
//�����ӣ����ʸýڵ㣬������child���
template <class T>
void LevelOrderTraversal(BinTree(T) BT) {
	deque<BinTree(T)> de;
	BinTree(T) B;
	if (!BT)return;
	de.push_back(BT);
	while (!de.empty()) {
		B = de.front();
		de.pop_front();
		cout << B->Data << "  ";
		if (B->Left)de.push_back(B->Left);
		if (B->Right)de.push_back(B->Right);
	}
}

//�����������Ĳ���ʵ��
//�ݹ鷨
template <class T>
Position Find(T x, BinTree(T) BST) {
	if (!BST)return NULL;
	if (x > BST->Data)
		return Find(x, BST->Right);
	else if (x < BST->Data)
		return Find(x, BST->Left);
	else
		return BST;//β�ݹ飬һ�����ѭ����ʽʵ��,ʵ������
}
template <class T>
Position IterFind(T x, BinTree(T) BST) {
	while (BST) {
		if (x > BST->Data)
			BST = BST->Right;
		else if (x < BST->Data)
			BST = BST->Left;
		else return BST;
	}
	return NULL;
}//����Ч�ʾ���������Depth��ƽ���������
template <class T>
Position FindMin(BinTree(T) BST) {
	if (!BST)return NULL;
	else if (!BST->Left)
		return BST;
	else
		return FindMin(BST->Left);
}//�ݹ���Min
template <class T>
Position FindMax(BinTree(T) BST) {
	if (BST) {
		while (BST->Right)
			BST = BST->Right;
	}
	return BST;
}//���������

//BST insert
template <class T>
BinTree(T) Insert(T x, BinTree(T) BST) {
	if (!BST) {
		BST = new TreeNode<int>(x);
		//BST->Data = x;
		//BST->Left = BST->Right = NULL;
	}
	else if (x < BST->Data)
		BST->Left = Insert(x, BST->Left);//�ݹ����������
	else if (x > BST->Data)
		BST->Right = Insert(x, BST->Right);

	return BST;
}

template <class T>
BinTree(T) Delete(T x, BinTree(T) BST) {
	Position tmp;
	if (!BST)cout << "<δ�ҵ�Ҫɾ����Ԫ��>" << endl;
	else if (x < BST->Data)
		BST->Left = Delete(x, BST->Left);
	else if (x > BST->Data)
		BST->Right = Delete(x, BST->Right);
	else if (BST->Left && BST->Right) {//��ɾ����Ԫ������child��Ϊnull
		tmp = FindMin(BST->Right);//������������СԪ�����ɾ�����
		BST->Data = tmp->Data;
		BST->Right = Delete(BST->Data, BST->Right);//��ɾ���ڵ��������ɾ����СԪ��
	}
	else {//��ɾ���ڵ�ֻ��һ�������ӽڵ�
		tmp = BST;
		if (!BST->Left)
			BST = BST->Right;
		else if (!BST->Right)
			BST = BST->Left;
		delete tmp;
	}//�����ڴ��������ͼ�������
	return BST;
} 