#include "matrix.h"

int main(){
	Mat mat1(5,5);
	cout <<"mat1=\n"<< mat1;
	Mat mat2(5, 5);
	cout <<"mat1=\n"<< mat2;
	cout <<"mat1+mat2=\n"<< mat1 + mat2;
	cout << "mat1-mat2=\n" << mat1 - mat2;
	system("pause");
	return 0;
}