#ifndef NODE_H
#define NODE_H
template <class T>
class Node {
	Node<T>* next;//ָ���̽���ָ��
public:
	T data;
	Node(const T& data, Node<T>* next=0) :data(data), next(next) {}

	void insertAfter(Node<T>* p);//�ڱ��������һ��ͬ����p

	Node<T>* deleteAfter();//ɾ�������ĺ�̽�㣬���������ַ

	Node<T>* nextNode();//��ȡ��̽��ĵ�ַ

	const Node<T>* nextNode()const;
};
//���غ�̽���ָ��
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
	 p->next = this->next;//p���ָ����ָ��ǰ���ĺ�̽��
	this->next = p;//��ǰ����ָ����ָ��p
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

