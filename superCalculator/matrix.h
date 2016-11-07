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
	//随机数填充
	_VOID fill();
	_VOID fill(_INT value);
	//矩阵输出
	friend ostream &operator <<(ostream &out,const Mat &mat_out);
	//字符串解析
	void strParse(string str);
	//矩阵输入
	friend istream &operator >>(istream &in, Mat mat_in);
	//矩阵加法
	Mat operator +(const Mat &mat_right);
	//矩阵减法
	Mat operator -(const Mat &mat_right);
	//深拷贝
	_VOID deepcopy(const Mat &mat_original);
	//拷贝构造
	Mat(Mat &mat_right);
	//赋值
	Mat &operator=(Mat &mat_right);
	//乘法
	Mat operator*(const Mat &mat_right);

	//~Mat();

private:
	_INT rows;
	_INT cols;
	_INT **element;

};
