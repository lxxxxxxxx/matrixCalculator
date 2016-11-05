#include <iostream>
#include "common.h"

class Mat{
public:

	Mat(void);
	Mat(_INT rows, _INT cols);
	//�������
	friend ostream &operator <<(ostream &out,const Mat &mat_out);
	//����ӷ�
	Mat &operator +(const Mat &mat_right);
	//�������
	Mat operator -(const Mat &mat_right);
	//���
	_VOID deepcopy(Mat &mat_original);
	//��������
	Mat(Mat &mat_right);
	//��ֵ
	Mat operator=(Mat &mat_right);
	//�˷�
	//Mat operator*(const Mat &mat_right);

	//~Mat();

private:
	_INT rows;
	_INT cols;
	_INT **element;

};
