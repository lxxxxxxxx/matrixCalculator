#include "testOperator.h"

_VOID testMatrixFirstStage(){
	Mat mat1;
	cout << "mat1默认构造的：    " << mat1 << endl;
	Mat mat2(5, 6);
	cout << "mat2随机数填充:     " << mat2 << endl;
	Mat mat3(6, 5, 8);
	cout << "mat3 value填充:      " << mat3 << endl;
	Mat mat4("1 2 3;4 5 6;7 8 9");
	cout << "mat4用字符串初始化：   " << mat4 << endl;
	Mat mat5(mat2);
	cout << "mat5用mat2初始化（复制构造）：   " << mat5 << endl;
	cout << "用随机数填充mat3    " << mat3.fill() << endl;
	cout << "用值填充mat3        " << mat3.fill(5);
	cout << "用mat2给mat1赋值    " << (mat1 = mat2) << endl;
	cout << "矩阵加法mat1+mat2   " << mat1 + mat2 << endl;
	cout << "矩阵减法mat1-mat2   " << mat1 - mat2 << endl;
	cout << "矩阵乘法mat1*mat2   " << mat1 * mat2 << endl;
	cout << "矩阵乘法mat2*mat3   " << mat2 * mat3 << endl;
	Mat mat6(2,3);
	cout << "矩阵转置mat2    " << mat6.transposition() << endl;
}