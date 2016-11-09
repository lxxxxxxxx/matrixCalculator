#include <iostream>
#include "common.h"
#include "matrixType.h"
#include <vector>

class Mat{
public:

	Mat(void);
	Mat(_INT rows, _INT cols);//��������ľ���
	Mat(_INT rows, _INT cols,_INT value);//value���ľ���
	Mat(string str);

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
	Mat strParse(string &str);
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

	~Mat();

private:
	_INT rows;
	_INT cols;
	_INT **element;

};
