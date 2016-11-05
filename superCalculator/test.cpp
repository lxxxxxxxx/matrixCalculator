#include "matrix.h"

int main(){
	Mat mat1(2,2,2);
	Mat mat2 = mat1;
	Mat mat3;
	cout << "mat1+mat2" << mat1.operator+(mat1) << endl;
	cout << "mat1+mat2" << mat1 + mat2 << endl;
	cout << "mat1-mat2" << mat1 - mat2 << endl;
	cout << "mat1*mat2" << mat1 * mat2 << endl;
	mat3=mat1 + mat2;
	cout << "mat1" << mat1 << endl;
	cout << "mat2" << mat2 << endl;
	mat3 = mat2 = mat1;
	cout << "mat3" << mat3 << endl;

	system("pause");
	return 0;
}