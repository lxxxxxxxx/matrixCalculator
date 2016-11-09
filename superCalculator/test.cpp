#include "matrix.h"
#include <string>
#include <vector>

int main(){
	string str = "123 1 2 3 4;4 5 8 6 4;54 5445 4";
	std::vector<std::string> subs;
	int pos;
	for (int i = 0; i < str.length(); i++){
		pos=str.find(";", i);
		string s = str.substr(i, pos);
		subs.push_back(s);
	}
	for (int i = 0; i < subs.size(); i++){
		cout << subs.at(i) << endl;
	}
	system("pause");
	return 0;
}