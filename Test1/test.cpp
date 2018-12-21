#include "pch.h"
#include "../linkedList/ListHeader.cpp"
#include "../linkedList/GenData.h"
#include "../linkedList/Copy.h"

int node::totalNodeCount = 0;
int linkList::totalNumberOfLists = 0;
class linkListTest : public ::testing::Test {
protected:
	void SetUp() override {

		const int numData = 10;
		myData = new genData[numData];
		myInt = new int[numData];


	}
	linkList myList;
	genData* myData;
	int *myInt;
};
TEST_F(linkListTest, firstRoundValues) {
	for (int iCnt = 0; iCnt < 10; iCnt++) {

		myInt[iCnt] = iCnt;
		myData[iCnt].setValue(iCnt);
	}
	myList.insert(myData[2]);
	myList.insert(myData[6]);
	myList.insert(myData[1]);
	myList.insert(myData[5]);
	myList.insert(myData[9]);
	myList.insert(myData[3]);
	EXPECT_EQ(myData[2].getValue(),2);
	EXPECT_EQ(myInt[2], 2);
	EXPECT_EQ(node::totalNodeCount, 8); //The number in the list + two
	EXPECT_EQ(linkList::totalNumberOfLists, 1);	//The number of lists.

	linkList newList = myList;	//Doesn't seem to matter 

	ASSERT_EQ(node::totalNodeCount, 16); //The number in the list + two
	ASSERT_EQ(linkList::totalNumberOfLists, 2);	//The number of lists.

	newList.deleteNode(myData[6]);
	myList.deleteNode(myData[6]);
	ASSERT_EQ(node::totalNodeCount, 14);
	ASSERT_EQ(linkList::totalNumberOfLists, 2);

	myList.insert(myData[8]);
	myList.deleteNode(myData[0]);

	ASSERT_EQ(node::totalNodeCount, 15);	//Why?
	ASSERT_EQ(linkList::totalNumberOfLists, 2);

	linkList newList2;
	newList2 = newList;

	ASSERT_EQ(node::totalNodeCount, 22);
	ASSERT_EQ(linkList::totalNumberOfLists, 3);

	testCopy(newList2);

	ASSERT_EQ(node::totalNodeCount, 22);
	ASSERT_EQ(linkList::totalNumberOfLists, 3);
	
	linkList newList3;
	newList3 = newList2;
	ASSERT_EQ(node::totalNodeCount, 29);
	ASSERT_EQ(linkList::totalNumberOfLists, 4);

	testCopy(linkList());
	linkList newList4 = myList;

	ASSERT_EQ(node::totalNodeCount, 37);
	ASSERT_EQ(linkList::totalNumberOfLists, 5);

	linkList newList5 = move(newList4);

	ASSERT_EQ(node::totalNodeCount, 37);
	ASSERT_EQ(linkList::totalNumberOfLists, 6);

	linkList newList6 = myList;
	linkList newList7;

	ASSERT_EQ(node::totalNodeCount, 47);
	ASSERT_EQ(linkList::totalNumberOfLists, 8);

	newList7 = move(newList6);
	ASSERT_EQ(node::totalNodeCount, 45);	//??
	ASSERT_EQ(linkList::totalNumberOfLists, 8);

}

TEST_F(linkListTest, secondRoundValues) {
	EXPECT_EQ(1, 1);

}
