#include <iostream>
#include "common.h"
#include "matrixType.h"

class Mat{
public:

	Mat(void);
	Mat(_INT rows, _INT cols);
	Mat(_INT rows, _INT cols,_INT value);
	Mat(_INT dimension, matrixType type);

	//SG
	_INT getRows();
	_INT getCols();
	_VOID setRows(_INT rows);
	_VOID setCols(_INT cols);
	//��������
	_VOID fill();
	_VOID fill(_INT value);
	//�������
	friend ostream &operator <<(ostream &out,const Mat &mat_out);
	//�ַ�������
	void strParse(string str);
	//��������
	friend istream &operator >>(istream &in, Mat mat_in);
	//����ӷ�
	Mat operator +(const Mat &mat_right);
	//�������
	Mat operator -(const Mat &mat_right);
	//���
	_VOID deepcopy(const Mat &mat_original);
	//��������
	Mat(Mat &mat_right);
	//��ֵ
	Mat &operator=(Mat &mat_right);
	//�˷�
	Mat operator*(const Mat &mat_right);

	//~Mat();

private:
	_INT rows;
	_INT cols;
	_INT **element;

};
