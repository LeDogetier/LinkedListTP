#pragma once


class SinglyLinkedListNode {
public:
	int data;
	SinglyLinkedListNode* next;

	SinglyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = nullptr;
	}
};

class SinglyLinkedList {
public:
	SinglyLinkedListNode* head;
	int size;

	SinglyLinkedList() {
		this->head = nullptr;
		this->size = 0;
	}

	void insertNodeAtHead(int data);
	void insertNodeAtTail(int data);
	void deleteNode(int position);
	void sortAscending();
};