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
//Mat::~Mat(){
//	for (_INT i = 0; i < this->mat.cols; i++){
//		delete[] this->mat.element[i];
//	}
//	delete[] this->mat.element;
//}

//矩阵输出
ostream &operator <<(ostream &out, const Mat &mat_out){
	if (mat_out.mat.rows==0||mat_out.mat.cols==0)
		out << "[\nNULL\n]";
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
	if (!(this->mat.rows == mat_right.mat.rows&&this->mat.cols == mat_right.mat.cols)){
		std::cout << "the nubmers of lines and columns of two matrixs should be identical." << endl;
		Mat mat_null(0,0);
		return mat_null;
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
_VOID Mat::deepcopy(Mat &mat_original){
	this->mat.rows = mat_original.mat.rows;
	this->mat.cols = mat_original.mat.cols;
	this->mat.element = new _INT*[mat_original.mat.rows];
	for (_INT i = 0; i < mat_original.mat.rows; i++){
		this->mat.element[i] = new _INT[mat_original.mat.cols];
	}
	for (_INT i = 0; i < mat_original.mat.rows; i++){
		for (_INT j = 0; j < mat_original.mat.cols; j++){
			this->mat.element[i][j] = mat_original.mat.element[i][j];
		}
	}
}
//拷贝构造
Mat::Mat(Mat &mat_right){
	cout << "调用了拷贝构造函数" << endl;
	deepcopy(mat_right);
}
//赋值
Mat Mat::operator=(Mat &mat_right){
	std::cout << "调用了赋值运算符" << endl;
	deepcopy(mat_right);
	return *this;
}
//乘法
//Mat operator*(const Mat &mat_right){
//	return;
//}