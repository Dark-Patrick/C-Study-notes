#ifndef NODE_H
#define NODE_H
template <class T>
class Node {
	Node<T>* next;//指向后继结点的指针
public:
	T data;
	Node(const T& data, Node<T>* next=0) :data(data), next(next) {}

	void insertAfter(Node<T>* p);//在本结点后插入一个同类结点p

	Node<T>* deleteAfter();//删除本结点的后继结点，并返回其地址

	Node<T>* nextNode();//获取后继结点的地址

	const Node<T>* nextNode()const;
};
//返回后继结点的指针
template<class T>
Node<T>* Node<T>::nextNode() {
	return next;
}
template<class T>
 const Node<T>* Node<T>::nextNode()const {
	return next;
}


 template<class T>
 void Node<T>::insertAfter(Node<T>* p) {
	 p->next = this->next;//p结点指针域指向当前结点的后继结点
	this->next = p;//当前结点的指针域指向p
 }


 template<class T>
 Node<T>* Node<T>::deleteAfter() {
	 Node<T>* tempPtr = this->next;
	 if (next = 0)
		 return 0;
	 this->next = tempPtr->next;
	 //free tempPtr;
	 //delete tempPtr;
	 return tempPtr;
 }

#endif // !NODE_H

