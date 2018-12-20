#include "pch.h"
//#include "../linkedList/ListHeader.h"
#include "../linkedList/ListHeader.cpp"
#include "../linkedList/GenData.h"


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
TEST_F(linkListTest, positiveValues) {
	EXPECT_EQ(myData[2].getValue(),2);
	EXPECT_GE(myInt[2], 1);
	EXPECT_GE(myList.totalNumberOfLists, 2);
	EXPECT_EQ(functDouble(2), 4);
	EXPECT_EQ(functDouble(3), 6);
}

TEST(functDoubleTest, negaticeValues) {
	EXPECT_EQ(functDouble(-2), -4);
	EXPECT_EQ(functDouble(-3), -6);
}