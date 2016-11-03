#include "matrix.h"

Mat::Mat(){
	mat.rows = 0;
	mat.cols = 0;
}
Mat::Mat(_INT rows, _INT cols){
	mat.rows = rows;
	mat.cols = cols;

	mat.element = new _INT*[rows];
	for (_INT i = 0; i <rows; i++){
		mat.element[i] = new _INT[cols];
	}
	srand(10);
	for (_INT i = 0; i < rows; i++){
		for (_INT j = 0; j < cols; j++){
			//用小于255的随机数填充
			mat.element[i][j] = rand() % 255;
		}	
	}
}
Mat::~Mat(){
	for (_INT i = 0; i < this->mat.cols; i++){
		delete[] this->mat.element[i];
	}
	delete[] this->mat.element;
}

//矩阵输出
ostream &operator <<(ostream &out, const Mat mat_out){
	if (mat_out.mat.rows==0||mat_out.mat.cols==0)
		out << "NULL";
	else
	{
		out << "[" << "\n";
		for (_INT i = 0; i < mat_out.mat.rows; i++){
			for (_INT j = 0; j < mat_out.mat.cols; j++)
				out << mat_out.mat.element[i][j] << " ";
			out << "\n";
		}
		out << "]" << "\n";
	}

		

	return out;
}
//矩阵加法
Mat &Mat::operator+(const Mat &mat_right){
	if (!(this->mat.rows == mat_right.mat.rows&&this->mat.rows == mat_right.mat.cols)){
		std::cout << "the nubmers of lines and columns of two matrixs should be identical." << endl;
		Mat mat_return(0,0);
		return mat_return;
	}
	else{
		Mat result(mat_right.mat.rows, mat_right.mat.cols);
		for (_INT i = 0; i < this->mat.rows; i++){
			for (_INT j = 0; j < this->mat.cols; j++){
				result.mat.element[i][j] = this->mat.element[i][j] + mat_right.mat.element[i][j];
			}
		}
		return result;
	}
	
}
//矩阵减法
Mat Mat::operator-(const Mat &mat_right){
	if (!(this->mat.rows == mat_right.mat.rows&&this->mat.rows == mat_right.mat.cols)){
		std::cout << "\nthe nubmers of lines and columns of two matrixs should be identical." << endl;
		Mat mat_return(0, 0);
		return mat_return;
	}
	else{
		Mat result(mat_right.mat.rows, mat_right.mat.cols);
		for (_INT i = 0; i < this->mat.rows; i++){
			for (_INT j = 0; j < this->mat.cols; j++){
				result.mat.element[i][j] = this->mat.element[i][j] - mat_right.mat.element[i][j];
			}
		}
		return result;
	}
	
}
//深拷贝
Mat Mat::deepcopy(){
	Mat result(mat.rows, mat.cols);
	for (_INT i = 0; i < mat.rows; i++){
		for (_INT j = 0; j < mat.cols; j++){
			result.mat.element[i][j] = mat.element[i][j];
		}
	}
	return result;
}
//拷贝构造
Mat::Mat(const Mat &mat_right){
	std::cout << "调用了拷贝构造" << endl;
	this->mat.cols = mat_right.mat.cols;
	this->mat.rows = mat_right.mat.rows;
	_INT **x;
	x= new _INT*[mat_right.mat.rows];
	for (_INT i = 0; i < mat_right.mat.rows; i++){
		x[i] = new _INT[mat_right.mat.cols];
	}

	for (_INT i = 0; i < mat_right.mat.rows; i++){
		for (_INT j = 0; j < mat_right.mat.cols; j++){
			x[i][j] = mat_right.mat.element[i][j];
		}
	}
	this->mat.element = x;
}
//赋值
Mat Mat::operator=(const Mat &mat_right){
	std::cout << "调用了赋值运算符" << endl;
	this->mat.cols = mat_right.mat.cols;
	this->mat.rows = mat_right.mat.rows;
	_INT **x;
	x = new _INT*[mat_right.mat.rows];
	for (_INT i = 0; i < mat_right.mat.rows; i++){
		x[i] = new _INT[mat_right.mat.cols];
	}

	for (_INT i = 0; i < mat_right.mat.rows; i++){
		for (_INT j = 0; j < mat_right.mat.cols; j++){
			x[i][j] = mat_right.mat.element[i][j];
		}
	}
	this->mat.element = x;
	return *this;
}
//乘法
//Mat operator*(const Mat &mat_right){
//	return;
//}