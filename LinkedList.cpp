#include<iostream>
#include<assert.h>

using namespace std;

#include"LinkedList.h"

//构造函数，链表初始化
LinkedList::LinkedList()
{
	head = NULL;
	length = 0;
}
//析构函数，遍历释放链表的每个节点
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
// 在链表的第i个元素的后面进行插入一个数据域为value的节点
//i=0 表示在最前面进行插入
void LinkedList::insert(int i, int value)
{
	int j = 1;
	Node *p = head;
	Node *ins;

        if(i < 0 || i > length)                //插入超出范围
	{
		cout<<"out range! fails to insert!"<<endl;
		return;
	}                                  

	ins = new Node;
	assert(ins != NULL);
	ins->data = value;

	if(i == 0)                         //i==0,在最前端插入
	{
		ins->next = head;
		head = ins;
		length++;
	}
	else                              //i!=0,在第i个元素后面插入新元素
	{
		while(p && j < i)             //遍历到第i个元素，准备进行插入
		{
			j++;
			p = p->next;
		}
		ins->next = p->next;
		p->next = ins;
		length++;                  //插入新元素后，链表长度加1
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
void LinkedList::quicksort2(Node *head, Node *tail)
{
	if(head != tail)
	{
	     Node *mid = partion(head, tail);
	//	display();
	     quicksort2(head, mid);
	     quicksort2(mid->next, tail);
	}
}
void LinkedList::quicksort()
{
	Node *tail = head;

	while(tail)    
	   tail = tail->next;
	quicksort2(head,tail);
}
Node * LinkedList::partion(Node *head, Node *tail)
{
	//每一次划分只交换数据域
	
	Node *p;
	Node *mid; //mid 指向划分出来的中间点
	int key, temp;

	mid = head;
	p = mid->next;
	key =head->data;   //定义轴点的数据域

	while(p != tail)
	{
	    if(p->data <= key)  // 比轴点小，出现逆序，需要和中间点交换数据域
	    {
		mid = mid->next;  // 中间点后移一个
                // 交换数据域，p->data 《——》 mid->data
		temp = p->data;
		p->data = mid->data;
		mid->data = temp;				
	    }
	    p = p->next;
	}
	// 交换数据域，head->data 《——》 mid->data	
	temp = mid->data;
	mid->data = head->data;
	head->data = temp;

        return mid;//返回划分出来的中间点。
}
//插入排序，升序
void LinkedList::insertsort()
{
	Node *p = head;
	Node *q, *r, *prer;


	if(!p || !p->next)
		return;                 //链表为空，或只有一个节点，直接返回

	q = p->next;
	while(q)
	{
		if(p->data > q->data)   // 出现逆序
		{
			r = head;
			prer = NULL;
			while(r->data < q->data)  //寻找插入点
			{
				prer = r;
				r = r->next;
			}
			if(prer == NULL)       // 要在最前面进行插入
			{
				p->next = q->next;
				q->next = r;
				head = q;
				q = p->next;
			}
			else                   //在插入点插入
			{
				p->next = q->next;
				prer->next = q;
				q->next = r;
				q = p->next;
			}
		}
		else                           //未出现逆序，向下遍历
		{
			p = p->next;
			q = q->next;
		}
	}
}

// 从大小为n的数组中进行链表的创建
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
