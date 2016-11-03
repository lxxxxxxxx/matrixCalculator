#include <iostream>
#include "common.h"


typedef struct{
	_INT rows;
	_INT cols;
	_INT **element;
}MATRIX;


class Mat{
public:

	Mat(void);
	Mat(_INT rows, _INT cols);
	//矩阵输出
	friend ostream &operator <<(ostream &out,const Mat mat_out);
	//矩阵加法
	Mat &operator +(const Mat &mat_right);
	//矩阵减法
	Mat operator -(const Mat &mat_right);
	//深拷贝
	Mat deepcopy();
	//拷贝构造
	Mat(const Mat &mat_right);
	//赋值
	Mat operator=(const Mat &mat_right);
	//乘法
	//Mat operator*(const Mat &mat_right);

	~Mat();

private:
	MATRIX mat;

};
