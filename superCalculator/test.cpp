#include "matrix.h"

int main(){
	Mat mat(3, 3);
	string str = "1         2 3;4 5 6;7 8 9";
	mat.strParse(str);
	system("pause");
	return 0;
}