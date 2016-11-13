#include <iostream>
#include <string>
#include <vector>

#include "common.h"
#include "matrixType.h"

class Mat{
public:
	//construction function
	Mat(void);
	Mat(_INT rows, _INT cols);//fill with random
	Mat(_INT rows, _INT cols, _INT value);//fill with value
	Mat(string str); //initialization with a string
	Mat(Mat &mat_right);//copy construction
	//destructor
	~Mat();

	//SG
	_INT getRows();
	_INT getCols();

	//fill
	Mat &fill();  //random
	Mat &fill(_INT value); //value
	//deep copy
	_VOID deepcopy(const Mat &mat_original);
	//aassignment
	Mat &operator=(Mat &mat_right);
	//output matrix
	friend ostream &operator <<(ostream &out,const Mat &mat_out);
	//string parse
	Mat strParse(string &str);
	//addition
	Mat operator +(const Mat &mat_right);
	//subtraction
	Mat operator -(const Mat &mat_right);
	//multiplication
	Mat operator*(const Mat &mat_right);
	//transposition
	Mat transposition();


private:
	 _INT rows;
	 _INT cols;
	 _INT **element;
};
