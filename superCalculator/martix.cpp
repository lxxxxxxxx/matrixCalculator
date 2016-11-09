#include "matrix.h"

Mat::Mat(){
	this->rows = 0;
	this->cols = 0;
}
Mat::Mat(_INT rows, _INT cols){
	this->rows = rows;
	this->cols = cols;
	this->element = new _INT*[rows];
	_FOR(i, rows){
		this->element[i] = new _INT[cols];
	}
	_FOR(i, rows){
		_FOR(j, cols){
			this->element[i][j] = rand() % 10;
		}
	}
}
Mat::Mat(_INT rows, _INT cols, _INT value){
	this->rows = rows;
	this->cols = cols;
	this->element = new _INT*[rows];
	_FOR(i, rows){
		this->element[i] = new _INT[cols];
	}
	_FOR(i, rows){
		_FOR(j, cols){
			this->element[i][j] = value;
		}
	}
}

Mat::~Mat(){
	cout << "析构" << endl;
	_FOR(i, this->rows){
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

//fill   ok
_VOID Mat::fill(){
	srand(10);
	_FOR(i, this->rows){
		_FOR(j, this->cols){
			this->element[i][j] = rand() % 10;
		}
	}
}
_VOID Mat::fill(_INT value){
	_FOR(i, this->rows){
		_FOR(j, this->cols){
			this->element[i][j] = value;
		}
	}
}


//ok
ostream &operator <<(ostream &out, const Mat &mat_out){
	if (mat_out.rows == 0 || mat_out.rows == 0)
		out << "[\nNULL\n]";
	else
	{
		out << "[" << "\n";
		_FOR(i, mat_out.rows){
			_FOR(j, mat_out.cols)
				out << mat_out.element[i][j] << " ";
			out << "\n";
		}
		out << "]" << "\n";
	}
	return out;
}
//字符串解析
_VOID Mat::strParse(string str){
	_INT rows = 0;
	_INT cols = 0;
	_INT n = 0;
	_INT first;
	while (1){
		if (str.find(";", n) == string::npos){
			break;
		}
		else{
			first = str.find(";");
			n = str.find(";", n) + 1;
			rows++;
		}
	}
	_FOR(i, first){
		cout << str.find(" ", i);
	}

	cout << "rows:    " << ++rows << "    first:    " << first << endl;
}
//矩阵输入
istream &operator >>(istream &in, Mat mat_in){
	string str_mat;
	in >> str_mat;
	str_mat.find(";");
	cout << str_mat;
	return in;
}

//ok
Mat Mat::operator+(const Mat &mat_right){
	if (!(this->rows == mat_right.rows&&this->cols == mat_right.cols)){
		std::cout << "the nubmers of lines and columns of two matrixs should be identical." << endl;
		Mat mat_null(0, 0);
		return mat_null;
	}
	else{
		Mat result(mat_right.rows, mat_right.cols);
		_FOR(i, this->rows){
			_FOR(j, this->cols){
				result.element[i][j] = this->element[i][j] + mat_right.element[i][j];
			}
		}
		return result;
	}

}
//ok
Mat Mat::operator-(const Mat &mat_right){
	if (!(this->rows == mat_right.rows&&this->rows == mat_right.rows)){
		std::cout << "\nthe nubmers of lines and columns of two matrixs should be identical." << endl;
		Mat mat_return(0, 0);
		return mat_return;
	}
	else{
		Mat result(mat_right.rows, mat_right.cols);
		_FOR(i, this->rows){
			_FOR(j, this->cols){
				result.element[i][j] = this->element[i][j] - mat_right.element[i][j];
			}
		}
		return result;
	}

}
//ok
_VOID Mat::deepcopy(const Mat &mat_original){
	this->rows = mat_original.rows;
	this->cols = mat_original.cols;
	this->element = new _INT*[mat_original.rows];
	_FOR(i, mat_original.rows){
		this->element[i] = new _INT[mat_original.cols];
	}
	_FOR(i, mat_original.rows){
		_FOR(j, mat_original.cols){
			this->element[i][j] = mat_original.element[i][j];
		}
	}
}
//ok
Mat::Mat(Mat &mat_right){
	cout << "调用了拷贝构造函数" << endl;
	deepcopy(mat_right);
}
//ok
Mat &Mat::operator=(Mat &mat_right){
	std::cout << "调用了赋值运算符" << endl;
	deepcopy(mat_right);
	return *this;
}
//ok
Mat Mat::operator*(const Mat &mat_right){
	if (this->cols != mat_right.rows){
		cout << "wrong operant!!!" << endl;
		Mat mat;
		return mat;
	}
	else{
		Mat result(this->rows, mat_right.cols, 0);
		_FOR(i, this->rows){
			_FOR(j, mat_right.cols){
				_FOR(k, this->cols){
					result.element[i][j] += (this->element[i][k] * mat_right.element[k][j]);
					//cout << result.element[i][j] << "   " << this->element[i][k] << "   " << mat_right.element[k][j] << endl;
					_INT a = result.element[i][j];
				}
			}
		}
		return result;
	}
}
