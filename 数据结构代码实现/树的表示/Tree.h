#pragma once
#include<iostream>
#include<stack>
#include<deque>
using namespace std;

#define BinTree(T) TreeNode<T>*
#define Position BinTree(T)
//二叉树
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

//二叉树遍历核心问题：二维结构的线性化
//递归方式实现
//先序遍历
template <class T>
void PreOrderTraversal(BinTree(T) BT) {
	if (BT) {
		cout << BT->Data << "  ";
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
	}
}
//中序遍历
template <class T>
void PreOrderTraversal2(BinTree(T) BT) {
	if (BT) {
		PreOrderTraversal2(BT->Left);
		cout << BT->Data << " ";
		PreOrderTraversal2(BT->Right);
	}
}
//后序遍历
template <class T>
void PreOrderTraversal3(BinTree(T) BT) {
	if (BT) {
		PreOrderTraversal3(BT->Left);
		PreOrderTraversal3(BT->Right);
		cout << BT->Data << " ";
	}
}
//先序，中序，后序遍历过程中经过节点的的路线一致，区别在于访问各节点的时机不同
//不做过多实现，画图找规律

//树的深度,利用后序遍历
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

//非递归遍历，直接堆栈实现
//中序遍历非递归遍历算法
template <class T>
void InOrderTraversal(BinTree(T) BT) {
	BinTree(T) B = BT;
	stack<BinTree(T)> s;
	while (B || !s.empty()) {
		while (B) {
			//cout << B->Data << "  ";  //在此输出数据，即为先序遍历
			s.push(B);

			/*if (B->Left == NULL) {
				B = B->Right;
				s.push(B);
			}*/ //后序遍历算法实现，不全，if (!s.empty()) 需在做修改

			B = B->Left;
		}
		if (!s.empty()) {
			B = s.top();//返回栈顶元素的引用
			s.pop();//返回void
			cout << B->Data << "  ";
			B = B->Right;
		}
	}
}

//层序遍历
//队列实现：遍历从根节点开始，先将root入队，后开始执行循环：
//结点出队，访问该节点，其左右child入队
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

//二叉搜索树的查找实现
//递归法
template <class T>
Position Find(T x, BinTree(T) BST) {
	if (!BST)return NULL;
	if (x > BST->Data)
		return Find(x, BST->Right);
	else if (x < BST->Data)
		return Find(x, BST->Left);
	else
		return BST;//尾递归，一般可用循环方式实现,实现如下
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
}//查找效率决定于树的Depth（平衡二叉树）
template <class T>
Position FindMin(BinTree(T) BST) {
	if (!BST)return NULL;
	else if (!BST->Left)
		return BST;
	else
		return FindMin(BST->Left);
}//递归找Min
template <class T>
Position FindMax(BinTree(T) BST) {
	if (BST) {
		while (BST->Right)
			BST = BST->Right;
	}
	return BST;
}//迭代找最大

//BST insert
template <class T>
BinTree(T) Insert(T x, BinTree(T) BST) {
	if (!BST) {
		BST = new TreeNode<int>(x);
		//BST->Data = x;
		//BST->Left = BST->Right = NULL;
	}
	else if (x < BST->Data)
		BST->Left = Insert(x, BST->Left);//递归插入左子树
	else if (x > BST->Data)
		BST->Right = Insert(x, BST->Right);

	return BST;
}

template <class T>
BinTree(T) Delete(T x, BinTree(T) BST) {
	Position tmp;
	if (!BST)cout << "<未找到要删除的元素>" << endl;
	else if (x < BST->Data)
		BST->Left = Delete(x, BST->Left);
	else if (x > BST->Data)
		BST->Right = Delete(x, BST->Right);
	else if (BST->Left && BST->Right) {//被删除的元素左右child不为null
		tmp = FindMin(BST->Right);//右子树中找最小元素填充删除结点
		BST->Data = tmp->Data;
		BST->Right = Delete(BST->Data, BST->Right);//在删除节点的右子树删除最小元素
	}
	else {//被删除节点只有一个或无子节点
		tmp = BST;
		if (!BST->Left)
			BST = BST->Right;
		else if (!BST->Right)
			BST = BST->Left;
		delete tmp;
	}//堆区内存操作，画图帮助理解
	return BST;
} 