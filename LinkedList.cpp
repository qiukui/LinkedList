#include<iostream>
#include<assert.h>

using namespace std;

#include"LinkedList.h"

//���������캯��
LinkedList::LinkedList()
{
	head = NULL;
	length = 0;
}
//���������������������յ�����ÿ���ڵ��Ĵ洢�ռ�
LinkedList::~LinkedList()
{
	Node *pNode, *qNode;
	pNode = NULL; qNode = head;

	while(qNode)
	{
		pNode = qNode;
        qNode = qNode->next;
		delete pNode;
	}
   
	head = NULL;
}
// �ڵ�i���ڵ���������������Ϊvalue�Ľڵ�
//i=0��ʾ����ǰ��λ�ò���
void LinkedList::insert(int i, int value)
{
	int j = 1;
	Node *p = head;
	Node *ins;

        if(i < 0 || i > length)
	{
		cout<<"out range! fails to insert!"<<endl;
		return;
	}                                  //������Ч��Χ������ʧ�ܣ�����0

	ins = new Node;
	assert(ins != NULL);
	ins->data = value;

	if(i == 0)                         //i==0,����ǰ������
	{
		ins->next = head;
		head = ins;
		length++;
	}
	else                              //i!=0,�ڵ�i��Ԫ�غ������в���
	{
		while(p && j < i)             //��������i��Ԫ�أ����������в���
		{
			j++;
			p = p->next;
		}
		ins->next = p->next;
		p->next = ins;
		length++;
	}

}

bool LinkedList::isEmpty()
{
	if(head == NULL)
		return true;
	else
		return false;
}
void LinkedList::deleteElem(int e)
{
	Node *p = head;
	Node *pre = NULL;
	while(p && p->data != e)
	{
		pre=p;
		p = p->next;
	}

	if(p == NULL)
	{ 
		cout<<"no such node whose value equals e"<<endl;
    	return;
	}

	if(pre == NULL)
	{
		head = head ->next;
		length--;
	}
	else
	{
		pre->next = p->next;
		length--;
	}

	free(p);
	
	return;
}

int LinkedList::getlength()
{
	return length;
}

//��������ʾ��
void LinkedList::sort()
{
	Node *p = head;
	Node *q, *r, *prer;


	if(!p || !p->next)
		return;                 //ֻ��һ��Ԫ�ػ�Ϊ�� ������������ֱ�ӷ��ء�

	q = p->next;
	while(q)
	{
		if(p->data > q->data)
		{
			r = head;
			prer = NULL;
			while(r->data < q->data)
			{
				prer = r;
				r = r->next;
			}
			if(prer == NULL)
			{
				p->next = q->next;
				q->next = r;
				head = q;
				q = p->next;
			}
			else
			{
				p->next = q->next;
				prer->next = q;
				q->next = r;
				q = p->next;
			}
		}
		else
		{
			p = p->next;
			q = q->next;
		}
	}
}


void LinkedList::create(int a[], int n)
{
	int i = 0;
	Node *p;
	for(i = n-1; i >=0; i--)
	{
		p = new Node;
		assert(p!=NULL);
		p->data = a[i];
		p->next = head;
		head = p;
		length++;
	}
}

void LinkedList::display()
{
	Node *p = head;
	if(isEmpty())
	   cout<<"there is nothing!  It is empty!"<<endl;
	else
	{
     //  cout<<"the list has "<<getlength()<<" members: "<<endl;
		while(p)
		{
			cout<<p->data<<" ";
			p = p->next;
		}
	}
	cout<<endl;
}
