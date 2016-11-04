#include "matrix.h"

int main(){
	Mat mat1(4,5);
	Mat mat2 = mat1;
	Mat mat3;
	cout << "mat1+mat2" << mat1 + mat2 << endl;
	mat3=mat1 + mat2;
	cout << "mat1" << mat1 << endl;
	cout << "mat2" << mat2 << endl;
	cout << "mat3" << mat3 << endl;


	system("pause");
	return 0;
}