// LinkedList.cpp : This is an exercise to see if I can create a linked list without looking up any examples. 
//

#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include "listHeader.h"
#include "Copy.h"
#include<vector>
using namespace std;

int node::totalNodeCount = 0;
int linkList::totalNumberOfLists = 0;


int main()
{
	{
	std::cout << std::boolalpha;
	int numData = 10;
	genData* myData = new genData[numData];
	int *myInt = new int[numData];

	cout << "\nPrint out the values of the data objects." << endl;

	for (int iCnt = 0; iCnt < numData; iCnt++) {
		myInt[iCnt] = iCnt;
		myData[iCnt].setValue(iCnt);
		cout << " " << myData[iCnt];	//Using overloaded operator
	}

	linkList myList;
	cout << "\nInserting into myList" << endl;
	myList.insert(myData[2]);
	myList.insert(myData[6]);
	myList.insert(myData[1]);
	myList.insert(myData[5]);
	myList.insert(myData[9]);
	myList.insert(myData[3]);

	linkList newList = myList;
	
	cout << "\nAttempt to delete data[6] in newList returned " << newList.deleteNode(myData[6]) << endl;
	cout << "\nNumber of nodes " << newList.show() << endl;

	cout << "About to call deleteNode on myList with data[6]\n";
	cout << "\nAttempt to deleteNode on myList with  data[6] returned " << myList.deleteNode(myData[6]) << endl;
	cout << "\nNumber of nodes " << myList.show() << endl;

	cout << "\nInserting myData[8] " << endl;
	myList.insert(myData[8]);
	cout << "\nDone inserting myData[8] " << endl;

	cout << "\nAttempt to delete data[0] returned " << myList.deleteNode(myData[0]) << endl;
	cout << "\nNumber of nodes in myList " << myList.show() << endl;
	cout << "\nNumber of nodes in newList " << newList.show() << endl;

	cout << "\nTotal number of linkLists before newList2  " << linkList::totalNumberOfLists;
	cout << "\nTotal number of nodes before newList2 " << node::totalNodeCount;


	linkList newList2;
	newList2 = newList;
	cout << "\nNumber of nodes in newList2 " << newList2.show() << endl;


	cout << "\nCalling testCopy" << endl;
	testCopy(newList2);
	cout << "\nMaking newList3" << endl;

	linkList newList3;
	cout << "\nSetting newList3 = newList2 (which should have 5 data nodes)" << endl;
	newList3 = newList2;

	cout << "\nCalling testCopy again" << endl;
	testCopy(linkList());

	
	linkList newList4 = myList;
	cout << "\nTry moving a link list to another - newList4 into newList5 using move constructor" << endl;
	linkList newList5 = move(newList4);
	
	cout << "\n number of myList nodes before moving to newList4 " << myList.show() << endl;
	linkList newList6 = myList;
	linkList newList7;
	
	cout << "\nTry using move assignemt operator from one list to another";
	newList7= move(newList6);


	vector<linkList> vec;
	cout << "\nTotal number of linkLists after making vector  " << linkList::totalNumberOfLists << " " << "Should be 4" << endl;
	cout << "\nPutting lists in vector ****************************************** " << endl;
	vec.push_back(move(myList));
	cout << "\nAdded first list" << endl;
	vec.push_back(move(newList));
	cout << "\nAdded second list" << endl;
	//	vec.push_back(move(newList));
	//	cout << "\nDone putting lists in vector ++++++++++++++++++++++++++++++++++++++++++ " << endl;

	cout << "\nShowing what you put in vec[1]" << endl;
	cout << "\nNumber of nodes \n" << vec[1].show() << endl;
	cout << "\nTotal number of linkLists  before clearing vector  " << linkList::totalNumberOfLists << " " << "Should be 4" << endl;
	cout << "\nClearing vector";
	vec.clear();
	cout << "\nDone clearing vector\n";
	cout << "\nTotal number of linkLists after clearing vector  " << linkList::totalNumberOfLists << " " << "Should be 4" << endl;
	cout << "\nTotal number of nodes after clearing vec " << node::totalNodeCount << " should be ??" << endl;
	
	list<genData> list1;
	list1.push_back(myData[2]);
	list1.push_back(myData[6]);
	list1.push_back(myData[1]);
	list1.push_back(myData[5]);
	list1.push_back(myData[9]);
	list1.push_back(myData[3]);

	cout << "\nUsing stl list" << endl;
	for (auto i = list1.begin(); i != list1.end(); ++i) {
		cout << i->getValue() << " ";
	}

	list1.sort(compare_function);
	cout << "\nUsing stl list sorted" << endl;
	for (auto i = list1.begin(); i != list1.end(); ++i) {
		cout << i->getValue() << " ";
	}

	list<genData> list2{ myData[7] ,myData[0] ,myData[8] };

	list2.sort(compare_function);
	cout << "\nSorted list2 before merge" << endl;
	for (auto i = list2.begin(); i != list2.end(); ++i) {
		cout << i->getValue() << " ";
	}
	list1.merge(list2, compare_function);
	cout << "\nUsing stl merge lists list1 with size = " << list1.size() << endl;
	for (auto i = list1.begin(); i != list1.end(); ++i) {
		cout << i->getValue() << " ";
	}

	cout << "\nUsing stl merge lists list2, likely empty" << endl;
	for (auto ii = list2.begin(); ii != list2.end(); ++ii) {
		cout << ii->getValue() << " ";
	}

	cout << "\nClearing the lists\n";
	list1.clear();
	list2.clear();
	cout << "\nDone clearing lists\n";

	
	cout << "\nTotal number of nodes before leaving scope " << node::totalNodeCount << "******************************" << endl;
	cout << "\nTotal number of linkLists before leaving scope " << linkList::totalNumberOfLists <<" "<< "******************************" << endl;
}
cout << "\nTotal number of linkLists just before return " << linkList::totalNumberOfLists << " " << "******************************" << endl;
cout << "\nTotal number of nodes just before return " << node::totalNodeCount << "******************************" << endl;

return 0;
}

