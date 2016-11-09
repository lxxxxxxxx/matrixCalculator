#include <iostream>
#include "common.h"
#include "matrixType.h"
#include <vector>

class Mat{
public:

	Mat(void);
	Mat(_INT rows, _INT cols);//随机数填充的矩阵
	Mat(_INT rows, _INT cols,_INT value);//value填充的矩阵
	Mat(string str);

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
	Mat strParse(string &str);
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

	~Mat();

private:
	_INT rows;
	_INT cols;
	_INT **element;

};
