#include "matrix.h"

int main(){
	Mat mat1(2, 3);
	cout << "Ëæ»úÊýÌî³ä\n" << mat1 << endl;
	Mat mat2(2, 3, 3);
	cout << "3Ìî³ä\n" << mat2 << endl;
	Mat mat3(3,0);
	cout << "µ¥Î»¾ØÕó\n" << mat3 << endl;
	Mat mat4(3, 1);
	cout << "¶Ô½Ç¾ØÕó\n" << mat4 << endl;
	Mat mat5(3, 2);
	cout << "ÉÏÈý½Ç¾ØÕó\n" << mat5 << endl;
	Mat mat6(3, 0);
	cout << "ÏÂÈý½Ç¾ØÕó\n" << mat6 << endl;
	system("pause");
	return 0;
}