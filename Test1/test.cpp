#include "pch.h"
#include "../linkedList/ListHeader.h"
#include "../linkedList/ListHeader.cpp"
#include "../linkedList/GenData.h"

int node::totalNodeCount = 0;
int linkList::totalNumberOfLists = 0;
class linkListTest : public ::testing::Test {
protected:
	void SetUp() override {

		const int numData = 10;
		myData = new genData[numData];
		myInt = new int[numData];

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
	}
	linkList myList;
	genData* myData;
	int *myInt;
};
TEST_F(linkListTest, firstRoundValues) {
	EXPECT_EQ(myData[2].getValue(),2);
	EXPECT_GE(myInt[2], 1);
	EXPECT_EQ(node::totalNodeCount, 8); //The number in the list + two
	EXPECT_EQ(linkList::totalNumberOfLists, 1);	//The number of lists.

}

class linkListTestCont : public ::testing::Test {
protected:
	void SetUp() override {
		linkList newList = myList;
	}
	linkList myList;
	genData* myData;
	int *myInt;
};
TEST_F(linkListTestCont, nextRoundValues) {
	EXPECT_EQ(myData[2].getValue(), 2);
	EXPECT_GE(myInt[2], 1);
	EXPECT_EQ(node::totalNodeCount, 16); //The number in the list + two
	EXPECT_EQ(linkList::totalNumberOfLists, 2);	//The number of lists.

}
