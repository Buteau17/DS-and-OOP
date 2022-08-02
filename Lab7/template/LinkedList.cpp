#include "LinkedList.h"

LinkedList::LinkedList() {
	// Constructor
	Head = NULL;
}

void LinkedList::Push_back(int x) {
	// TODO : Insert a node to the end of the linked list, the node¡¦s value is x.
	if (!Head) {
		Head = new ListNode(x);
		return;
	}
	ListNode* temp = Head;
	while(temp->next){
		temp = temp->next;
	}
	temp->next = new ListNode(x);
}

void LinkedList::Push_front(int x) {
	if (!Head) {
		Head = new ListNode(x);
		return;
	}
	//cout << "head" << endl;
	ListNode* temp = new ListNode(x);

	temp->next = Head;
	Head = temp;
}

void LinkedList::Insert(int index, int x) {
	// TODO : Insert a node to the linked list at position ¡§index¡¨, the node's
	// value is x. The index of the first node in the linked list is 0.

	ListNode* temp = new ListNode(x);
	if (index == 0) {
		Push_front(x);
	}
	else {
		ListNode* tmp = Head;
		for (int i = 1; i < index; i++) {
			tmp = tmp->next;
		}
		ListNode* temp = tmp->next;
		tmp->next = new ListNode(x);
		tmp->next->next = temp;



	}


}

void LinkedList::Delete(int index) {
	// TODO : Remove the node with index ¡§index¡¨ in the linked list.
	if (index == 0) {
		Head = Head->next;
	}
	else {
		ListNode* tmp = Head;
		for (int i = 1; i < index; i++) {
			tmp = tmp->next;
		}
		tmp->next = tmp->next->next;
	}
}

void LinkedList::Reverse() {
	// TODO : Reverse the linked list.
	// Example :
	//
	// Original List : 1 -> 2 -> 3 -> 4 -> NULL
	// Updated List  : 4 -> 3 -> 2 -> 1 -> NULL
	ListNode* tmp = Head;
	ListNode* pre = NULL, * cur = NULL;

	while (tmp != NULL) {
		cur = new ListNode(tmp->val);
		cur->next = pre;
		pre = cur;
		//cout << tmp->val << endl;
		tmp = tmp->next;
	}
	Head = pre;
}

void LinkedList::Swap(int index_1, int index_2) {
	if (index_1 == index_2) return;

	// TODO : Swap two nodes in the linked list
	// Example : 
	// index_1 : 1   ,  index_2 : 3
	// 
	// Original List : 1 -> 2 -> 3 -> 4 -> NULL
	// Updated List  : 1 -> 4 -> 3 -> 2 -> NULL

	if (index_1 > index_2) {
		int tmp = index_1;
		index_1 = index_2;
		index_2 = tmp;
	}



	int arr[1000];
	int cnt = 0;
	ListNode* tmp = Head;
	while (tmp) {
		//cout << tmp->val << ' ';
		arr[cnt++] = tmp->val;
		tmp = tmp -> next;
	}
	//cout << endl;
	//cout << index_1 << ' ' << index_2 << '\n';
	int temp = arr[index_1];
	arr[index_1] = arr[index_2];
	arr[index_2] = temp;

	tmp = Head;
	for (int i = 0; i < cnt; i++) {
		//cout << arr[i] << ' ';
		tmp->val = arr[i];
		tmp = tmp->next;
	}
	return;





	//if(index_1 == 0)


	//ListNode* tmp = Head;
	ListNode* node1 = NULL;
	ListNode* node2 = NULL;
	int size = 0;
	while (tmp->next != NULL) {
		if (size == index_1-1)
			node1 = tmp;
		if (size == index_2-1) {
			node2 = tmp;
			break;
		}
		tmp = tmp->next;
		size++;
	}
	cout << index_1 << ' ' << index_2 << endl;
	/*
	if (node2 == NULL) {
		tmp = Head;
		while (tmp->next != NULL) {
			node2 = tmp;
		}
	}
	cout << node2->val << endl;
	*/
	if (index_1 == 0) { // 3 5 2, s 0 1
		cout << Head->val << ' ' << node2->val << endl;
		ListNode* tmp11 = Head;
		ListNode* tmp22 = node2->next;
		ListNode* tmp1 = Head->next;
		ListNode* tmp2 = node2->next->next;
		node2->next->next = tmp1;
		Head = tmp22;
		Head->next = tmp2;
		//node1->next = tmp22;
		node2->next = tmp11;
		cout << Head->val << Head->next->val << endl;
		return;
	}
	ListNode* tmp11 = node1 ->next;
	ListNode* tmp22 = node2 ->next;
	ListNode* tmp1 = node1->next->next;
	ListNode* tmp2 = node2->next->next;
	node2->next->next = tmp1;
	node1->next->next = tmp2;
	node1->next = tmp22;
	node2->next = tmp11;

	//int temp = node1->data;
	//node1->data = node2->data;
	//node2->data = temp;
}

void LinkedList::Print() {
	cout << "List:";
	// TODO : Print all the elements in the linked list in order.
	ListNode* tmp = Head;
	while (tmp) {
		cout << ' ' << tmp->val;
		tmp = tmp->next;
	}
	cout  << endl;
}

LinkedList::~LinkedList()
{
	while (Head) {
		ListNode* temp = Head;
		Head = Head->next;
		delete temp;
	}
}
