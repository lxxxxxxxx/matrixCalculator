#include "testOperator.h"

_VOID testMatrixFirstStage(){
	Mat mat1;
	cout << "mat1Ĭ�Ϲ���ģ�    " << mat1 << endl;
	Mat mat2(5, 6);
	cout << "mat2��������:     " << mat2 << endl;
	Mat mat3(6, 5, 8);
	cout << "mat3 value���:      " << mat3 << endl;
	Mat mat4("1 2 3;4 5 6;7 8 9");
	cout << "mat4���ַ�����ʼ����   " << mat4 << endl;
	Mat mat5(mat2);
	cout << "mat5��mat2��ʼ�������ƹ��죩��   " << mat5 << endl;
	cout << "����������mat3    " << mat3.fill() << endl;
	cout << "��ֵ���mat3        " << mat3.fill(5);
	cout << "��mat2��mat1��ֵ    " << (mat1 = mat2) << endl;
	cout << "����ӷ�mat1+mat2   " << mat1 + mat2 << endl;
	cout << "�������mat1-mat2   " << mat1 - mat2 << endl;
	cout << "����˷�mat1*mat2   " << mat1 * mat2 << endl;
	cout << "����˷�mat2*mat3   " << mat2 * mat3 << endl;
	Mat mat6(2,3);
	cout << "����ת��mat2    " << mat6.transposition() << endl;
}