#ifndef COPY_H
#define COPY_H

#include"listHeader.h"

linkList& testCopy(linkList& source) {
	cout << "\nPassing by reference and returning a linkList by reference " << endl;
	return source;
}

//linkList& testCopy(linkList source) {
//	cout << "\nPassing by value and returning a linkList by reference " << endl;
//	return source;
//}

linkList testCopy(linkList&& source) {
	cout << "\nPassing and returning a linkList by rvalue " << endl;
	return source;
}

#endif 

