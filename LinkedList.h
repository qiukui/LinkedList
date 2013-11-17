#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node
{
	int data;
	struct Node *next;
}Node;

class LinkedList
{
private:
	Node *head;
	int length;
public:
	LinkedList();
	~LinkedList();
	void insert(int i, int value);
	void deleteElem(int e);
	void create(int *a, int n);
	bool isEmpty();
	void insertsort();
	void quicksort();
	void quicksort2(Node *head, Node *tail);
	Node *partion(Node *head, Node *tail);
	int getlength();

	void display();
//	implement create, insert, remove and sort methods.
};

#endif
