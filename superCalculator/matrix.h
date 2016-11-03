#include <iostream>
#include "common.h"


typedef struct{
	_INT rows;
	_INT cols;
	_INT **x;
}MATRIX;


class Mat{
public:

	Mat(void);
	Mat(_INT rows, _INT cols);
	//�������
	friend ostream &operator <<(ostream &out, Mat mat_out);
	//����ӷ�
	Mat operator +( Mat &mat_right);
	//�������
	Mat operator -( Mat &mat_right);
	//���
	Mat deepcopy();
	//��ֵ
	Mat operator=(Mat &mat_right);

	~Mat(){}

private:
	MATRIX mat;

};
