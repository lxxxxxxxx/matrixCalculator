#include "matrix.h"

Mat::Mat(){
	this->rows = 0;
	this->cols = 0;
}
Mat::Mat(_INT rows, _INT cols){
	this->rows = rows;
	this->cols = cols;

	this->element = new _INT*[rows];
	for (i,rows){
		this->element[i] = new _INT[cols];
	}
	srand(10);
	for (i,rows){
		for (j,cols){
			//用小于255的随机数填充
			this->element[i][j] = rand() % 255;
		}	
	}
}
Mat::Mat(_INT rows, _INT cols, _INT value){
	this->rows = rows;
	this->cols = cols;

	this->element = new _INT*[rows];
	for (i, rows){
		this->element[i] = new _INT[cols];
	}

	for (i, rows){
		for (j, cols){
			//用小于255的随机数填充
			this->element[i][j] = value;
		}
	}
}

Mat::~Mat(){
	for (i,this->cols){
		delete[] this->element[i];
	}
	delete[] this->element;
}
_INT Mat::getRows(){
	return this->rows;
}
_INT Mat::getCols(){
	return this->cols;
}
_VOID Mat::setRows(_INT rows){
	this->rows = rows;
}
_VOID Mat::setCols(_INT cols){
	this->cols = cols;
}

//worked
ostream &operator <<(ostream &out,const Mat &mat_out){
	if (mat_out.rows==0||mat_out.rows==0)
		out << "[\nNULL\n]";
	else
	{
		out << "[" << "\n";
		for (i, mat_out.rows){
			for (j,mat_out.cols)
				out << mat_out.element[i][j] << " ";
			out << "\n";
		}
		out << "]" << "\n";
	}
	return out;
}
//矩阵输入
//istream &operator >>(istream &in, Mat mat_in){
//	string str_mat;
//	in >> str_mat;
//
//}

//worked
Mat Mat::operator+(const Mat &mat_right){
	if (!(this->rows == mat_right.rows&&this->cols == mat_right.cols)){
		std::cout << "the nubmers of lines and columns of two matrixs should be identical." << endl;
		Mat mat_null(0,0);
		return mat_null;
	}
	else{
		Mat result(mat_right.rows, mat_right.cols);
		for (i,this->rows){
			for (j,this->cols){
				result.element[i][j] = this->element[i][j] + mat_right.element[i][j];
			}
		}
		return result;
	}
	
}
//worked
Mat Mat::operator-(const Mat &mat_right){
	if (!(this->rows == mat_right.rows&&this->rows == mat_right.rows)){
		std::cout << "\nthe nubmers of lines and columns of two matrixs should be identical." << endl;
		Mat mat_return(0, 0);
		return mat_return;
	}
	else{
		Mat result(mat_right.rows, mat_right.cols);
		for (i,this->rows){
			for (j,this->cols){
				result.element[i][j] = this->element[i][j] - mat_right.element[i][j];
			}
		}
		return result;
	}
	
}
//worked
_VOID Mat::deepcopy(const Mat &mat_original){
	this->rows = mat_original.rows;
	this->cols = mat_original.cols;
	this->element = new _INT*[mat_original.rows];
	for (i,mat_original.rows){
		this->element[i] = new _INT[mat_original.cols];
	}
	for (i,mat_original.rows){
		for (j,mat_original.cols){
			this->element[i][j] = mat_original.element[i][j];
		}
	}
}
//worked
Mat::Mat(Mat &mat_right){
	cout << "调用了拷贝构造函数" << endl;
	deepcopy(mat_right);
}
//worked
Mat &Mat::operator=(Mat &mat_right){
	std::cout << "调用了赋值运算符" << endl;
	deepcopy(mat_right);
	return *this;
}
//woeked
Mat Mat::operator*(const Mat &mat_right){
	if (this->cols != mat_right.rows){
		cout << "wrong operant!!!" << endl;
		Mat mat;
		return mat;
	}
	else{
		Mat result(this->rows, mat_right.cols,0);
		for (i, this->rows){
			for (j, mat_right.cols){
				for (k, this->cols){
					result.element[i][j] += (this->element[i][k] * mat_right.element[k][j]);
					cout << result.element[i][j] << "   " << this->element[i][k] << "   " << mat_right.element[k][j] << endl;
					_INT a = result.element[i][j];
				}
			}
		}
		return result;
	}
}