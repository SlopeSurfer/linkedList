#ifndef LIST_H 
#define LIST_H
#include "GenData.h"

class node {
	genData nodeData;
	node* next = NULL;
public:

//		static int totalNodeCount;
	int totalNodeCount;

	node() {
		cout << "\nCalling node constructor with no arguments\n";
		totalNodeCount++;
	};
	node(genData inData) :nodeData(inData) {
		cout << "Calling node constructor with Data\n";
		totalNodeCount++;
	};
	~node();
	node(const node& toCopy);
	node& operator=(const node & source);
	node* const getNext()const { return next; }
	void const setNext(node* inNext) { next = inNext; }
	int const getValue()const { return nodeData.getValue(); }
	genData const getData()const { return nodeData; }

};

class linkList {
	node* head;
	node* tail;
	void const insert(genData inData, node* startNode)const;
	int const show(node* startNode, int nodeCount);
	int const deleteList(node* startNode, int nodeCount);
	bool const deleteNode(genData inData, node* startNode) const;

public:
//	static int totalNumberOfLists;
	int totalNumberOfLists =2;
	linkList();
	~linkList();
	linkList(const linkList& toCopy);
	linkList(linkList&& other);
	linkList& operator=(const linkList& toCopy);
	linkList& operator=(linkList&& other);

	void copyNodes(node* startNode, node* checkTail);
	void const insert(genData inData);
	int const show();
	int const deleteList();
	bool const deleteNode(genData inData);
	node* const getHead()const;
	node* const getTail()const;
	void const makeNewNode(genData inData, node* nextNode, node* thisNode)const;
};
bool compare_function(genData& s1, genData& s2);

//Adding a function just to see if I can get at it in google test.

int functDouble(int inPut);

#endif


