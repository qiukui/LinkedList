#include<iostream>
#include<assert.h>

using namespace std;

#include"LinkedList.h"

//单链表构造函数
LinkedList::LinkedList()
{
	head = NULL;
	length = 0;
}
//单链表析构函数——回收单链表每个节点的存储空间
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
// 在第i个节点后面插入数据域为value的节点
//i=0表示在最前面位置插入
void LinkedList::insert(int i, int value)
{
	int j = 1;
	Node *p = head;
	Node *ins;

    if(i < 0 || i > length)
	{
		cout<<"out range! fails to insert!"<<endl;
		return;
	}                                  //超出有效范围，插入失败，返回0

	ins = new Node;
	assert(ins != NULL);
	ins->data = value;

	if(i == 0)                         //i==0,在最前面插入
	{
		ins->next = head;
		head = ins;
		length++;
	}
	else                              //i!=0,在第i个元素后面进行插入
	{
		while(p && j < i)             //遍历到第i个元素，在其后进行插入
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

//升序排序示例
void LinkedList::sort()
{
	Node *p = head;
	Node *q, *r, *prer;


	if(!p || !p->next)
		return;                 //只有一个元素或为空 ，不用排序；直接返回。

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