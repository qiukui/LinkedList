#include<iostream>
#include"LinkedList.h"

using namespace std;

int main()
{
	int a[]={8,4,5,2};
        LinkedList testlist1, testlist2;

	cout<<"------------the first test:"<<endl<<endl;
	testlist1.create(a,4);
	cout<<"------------create a linkedlist from array a with size 4: "<<"-----------display() should come out  as the same with array a, which is 8 4 5 2"<<endl<<endl;
	testlist1.display();
	cout<<"------------delete an element whose value is 4 from testlist1, the expected result should be 8 5 2 "<<endl<<endl;
	testlist1.deleteElem(4);
	testlist1.display();
	cout<<"------------insert an element whose value is 7 in the testlist1 after the second element, the expected result should be 8 5 7 2"<<endl<<endl;
        testlist1.insert(2,7);
	testlist1.display();
	cout<<"------------sort the testlist1, the expected should be 2 5 7 8"<<endl<<endl;
	testlist1.quicksort();
	testlist1.display();

	cout<<endl<<endl;

	cout<<"------------the second test:"<<endl<<endl;
	testlist2.create(a,4);
	cout<<"------------create a linkedlist from array a with size 4: "<<"-----------display() should come out  as the same with array a, which is 8 4 5 2"<<endl<<endl;
	testlist2.display();
	cout<<"------------delete an element whose value is 10 from testlist2, the expected result should show some error messages, since there is no elem whose value is 10 "<<endl<<endl;
	testlist2.deleteElem(10);
	testlist2.display();
	cout<<"------------insert an element whose value is 7 in the testlist2 at the most beginning, the expected result should be 7 8 4 5 2"<<endl<<endl;
        testlist2.insert(0,7);
	testlist2.display();
	cout<<"------------sort the testlist2, the expected should be 2 4 5 7 8"<<endl<<endl;
	testlist2.insertsort();
	testlist2.display();
	getchar();
	return 1;
}
