#include "matrix.h"

int main(){
	Mat mat1(2, 3);
	cout << "��������\n" << mat1 << endl;
	Mat mat2(2, 3, 3);
	cout << "3���\n" << mat2 << endl;
	Mat mat3(3,0);
	cout << "��λ����\n" << mat3 << endl;
	Mat mat4(3, 1);
	cout << "�ԽǾ���\n" << mat4 << endl;
	Mat mat5(3, 2);
	cout << "�����Ǿ���\n" << mat5 << endl;
	Mat mat6(3, 0);
	cout << "�����Ǿ���\n" << mat6 << endl;
	system("pause");
	return 0;
}