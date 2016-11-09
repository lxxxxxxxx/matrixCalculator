#include "matrix.h"
#include <string>
#include <vector>

int main(){
	string str = "1 2 3;4 5 6;7 8 9";
	Mat mat(str);
	cout << mat << endl;

	system("pause");
	return 0;
}