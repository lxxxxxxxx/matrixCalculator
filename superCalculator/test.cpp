#include "matrix.h"

int main(){
	Mat mat1(4,5);
	Mat mat2 = mat1;
	Mat mat3;
	mat3=mat1 + mat2;
	cout << mat1 << endl << mat2 << endl << mat3 << endl;


	system("pause");
	return 0;
}