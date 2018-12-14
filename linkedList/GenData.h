#ifndef GDATA_H
#define GDATA_H
#include <string>
#include <iostream>
using namespace std;

enum sizes { isLessThan, isEqualTo, isGreaterThan };

class genData {
	int value;
	string name;
public:
	genData() { value = -1; name = ""; };
	genData(int inValue, string inName) :value(inValue), name(inName) {}
	void showNode() { cout << "Value " << value << " and name " << name << endl; }
	int const getValue()const { return value; }
	void const setValue(int inValue) { value = inValue; }

	int const compare(int with)const {
		if (value == with) {
			return isEqualTo;
		}
		else if (value < with) {
			return isLessThan;
		}
		else {
			return isGreaterThan;
		}
	}
	friend ostream &operator<<(ostream &output, genData & out) {
		output << out.getValue();
		return output;
	}
};
#endif
