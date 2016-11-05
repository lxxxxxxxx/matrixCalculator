#include <iostream>
#include "common.h"

class Mat{
public:

	Mat(void);
	Mat(_INT rows, _INT cols);
	//矩阵输出
	friend ostream &operator <<(ostream &out,const Mat &mat_out);
	//矩阵加法
	Mat &operator +(const Mat &mat_right);
	//矩阵减法
	Mat operator -(const Mat &mat_right);
	//深拷贝
	_VOID deepcopy(Mat &mat_original);
	//拷贝构造
	Mat(Mat &mat_right);
	//赋值
	Mat operator=(Mat &mat_right);
	//乘法
	//Mat operator*(const Mat &mat_right);

	//~Mat();

private:
	_INT rows;
	_INT cols;
	_INT **element;

};
