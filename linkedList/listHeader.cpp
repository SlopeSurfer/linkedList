#include "ListHeader.h"

node::~node() {	//New is never called on next. next is just a pointer to some existing node. Just because
			//it is not = to NULL does not mean that it has any memory to clear. 
			//Note, it is OK to delete it if it = NULL. But, if it does not equal NULL and has never been declared with 
			//a new, then deleting it can cause a problem. 
	cout << "\nCalling node destructor";
	totalNodeCount--;
	next = nullptr;
//	delete next;	//Likely never necessary.
}

node::node(const node& toCopy) {
	cout << "Calling node copy constructor\n" << endl;
	nodeData = toCopy.nodeData;
	next = toCopy.next;
}

node& node::operator=(const node & source) {
	if (&source != this) {
		cout << "\nCalling node overloaded assignment operator " << endl;
		this->nodeData = source.nodeData;
		this->next->setNext(source.getNext());
	}
	return *this;
}

linkList::linkList() {
	cout << "\nCalling linkList constructor\n";
	head = new node;
	tail = new node;
	head->setNext(tail);
	totalNumberOfLists++;
}
linkList::~linkList() {
	cout << "\nCalling linkList destructor" << endl;
	int nodeCount = 0;
	deleteList(head, nodeCount);
	delete tail;
	tail = NULL;
	totalNumberOfLists--;
}

linkList::linkList(const linkList& toCopy) {
	cout << "\nCalling linkList copy constructor " << endl;
	head = new node;
	tail = new node;
	head->setNext(tail);
	copyNodes(toCopy.getHead(), toCopy.getTail());
	totalNumberOfLists++;
}
linkList& linkList::operator=( const linkList& toCopy) {
	cout << "\nCalling linkList assignment operator" << endl;

	//Note that head and tail were already created, because the assignment operator is only called when the object already exists. 
	copyNodes(toCopy.getHead(), toCopy.getTail());

	return *this;
}
linkList::linkList(linkList&& other) :head(nullptr), tail(nullptr) {
	cout << "\nCalling linkList move constructor" << endl;

	head = other.head;
	tail = other.tail;
	other.head = nullptr;
	other.tail = nullptr;
	totalNumberOfLists++;	//I don't have a good rationalization for adding to lists here. I just see that the compiler
							//destructs additional linkLists when the whole thing goes out of scope. 
}
linkList& linkList::operator=(linkList&& other){
	cout << "\nCalling linkList move assignment operator" << endl;
	if (this != &other) {
		head = other.head;
		tail = other.tail;
		other.head = nullptr;
		other.tail = nullptr;
//So, why not add to the linkList count the same way you did for the move constructor. All I can come up with is that 
//since you have already created the linkList before getting here, you are not adding it. 
//By the same rationalization, two nodes that were created during the move constructor are not created here. So, 
//reduce the number in nodec by two (yikes!!!). 
//		node::totalNodeCount--;
//		node::totalNodeCount--;

	}
	return *this;
}
void linkList::copyNodes(node* startNode, node* checkTail) {
	if (startNode->getNext() != checkTail) {
		this->insert(startNode->getNext()->getData());
		copyNodes(startNode->getNext(), checkTail);
	}
}

void const linkList::insert(genData inData, node* startNode)const {

	//Inert's job is to take a value, figure out where it belongs in the list, and create 
	// a new node at that spot with the given value.
	if (startNode->getNext() == tail) {
		// Put the new node here, regardless of value.
		makeNewNode(inData, startNode->getNext(), startNode);
	}
	else {
		int result = startNode->getNext()->getData().compare(inData.getValue());
		if (result == isLessThan) {
			//Keep looking
			insert(inData, startNode->getNext());
		}
		else {
			//This is the case of finding that the new one is less than the next one. So, you want to 
			//make a new node, give it the value, and place it. 
			makeNewNode(inData, startNode->getNext(), startNode);
		}
	}
}
int const linkList::show(node* startNode, int nodeCount) {
	if (startNode == nullptr) {
		cout << "\nNot a valid linkLink list\n";
	}

	else if(startNode->getNext() != tail) {

		nodeCount = 1;
		cout << " " << startNode->getNext()->getValue();
		nodeCount += show(startNode->getNext(), nodeCount);

	}
	return nodeCount;
}
int const linkList::deleteList(node* startNode, int nodeCount) {
	if (startNode != tail) {

		nodeCount++;
		deleteList(startNode->getNext(), nodeCount);
		delete startNode;
		startNode = NULL;
	}
//	cout << "\nNumber of nodes found/deleted in deleteList " << nodeCount << endl;
	return nodeCount;
}
bool const linkList::deleteNode(genData inData, node* startNode) const {

	if (startNode->getNext() == tail) {
		return false;
	}
	int result = startNode->getNext()->getData().compare(inData.getValue());
	if (result != isEqualTo) {
		//Keep looking
		return deleteNode(inData, startNode->getNext());

	}
	else {
		//You found it, cut it out of the list.
		node* tempNode = new node;
		tempNode->setNext(startNode->getNext());
		startNode->setNext(startNode->getNext()->getNext());
		delete tempNode->getNext();	//This is where you actually free up the memory of the node being removed.
		delete tempNode;
		return true;
	}
}
void const linkList::makeNewNode(genData inData, node* nextNode, node* thisNode)const {
	node* newNode = new node(inData);
	newNode->setNext(nextNode);
	thisNode->setNext(newNode);

}
void const linkList::insert(genData inData) {
	insert(inData, head);
}
int const linkList::show() {
	int nodeCount = 0;
	return show(head, nodeCount) - 1;
	//		return nodeCount;
}
int const linkList::deleteList() {
	int nodeCount = 0;
	deleteList(head, nodeCount);
	return nodeCount;
}
bool const linkList::deleteNode(genData inData) {
	return deleteNode(inData, head);

}
node* const linkList::getHead()const { return head; }
node* const linkList::getTail()const { return tail; }

bool compare_function(genData& s1, genData& s2)
{
	return (s1.getValue() < s2.getValue());
}

int functDouble(int inPut)
{
	return(2 * inPut);
}
