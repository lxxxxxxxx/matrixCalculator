#include "matrix.h"

Mat::Mat(){
	this->rows = 0;
	this->cols = 0;
}
Mat::Mat(_INT rows, _INT cols){
	this->rows = rows;
	this->cols = cols;
	this->element = new _INT*[rows];
	for (i, rows){
		this->element[i] = new _INT[cols];
	}
	for (i, rows){
		for (j, cols){
			this->element[i][j] = rand()%10;
		}
	}
}
Mat::Mat(_INT rows, _INT cols,_INT value){
	this->rows = rows;
	this->cols = cols;
	this->element = new _INT*[rows];
	for (i,rows){
		this->element[i] = new _INT[cols];
	}
	for (i,rows){
		for (j,cols){
			this->element[i][j] = value;
		}	
	}
}
Mat::Mat(_INT dimension,matrixType type){
	this->rows = dimension;
	this->cols = dimension;
	this->element = new _INT*[dimension];
	for (i, rows){
		this->element[i] = new _INT[dimension];
	}

	switch (type){
	case UNIT_MATRIX:{
						 for (i, rows){
							 for (j, cols){
								 if (i == j)
									 this->element[i][j] = 1;
								 else
									 this->element[i][j] = 0;
							 }
						 }

	}
		break;
	case DIAGONAL_MATRIX:{
							 for (i, rows){
								 for (j, cols){
									 if (i == j)
										 this->element[i][j] = rand()%10;
									 else
										 this->element[i][j] = 0;
								 }
							 }
	}
		break;
	case UPPER_TRIANGULAR_MATRIX:{
									 for (i, rows){
										 for (j, cols){
											 if (i <= j)
												 this->element[i][j] = rand() % 10;
											 else
												 this->element[i][j] = 0;
										 }
									 }
	}
		break;
	case LOWER_TRIANGULAR_MATRIX:{
									 for (i, rows){
										 for (j, cols){
											 if (i >= j)
												 this->element[i][j] = rand() % 10;
											 else
												 this->element[i][j] = 0;
										 }
									 }
	}
		break;
	}
}



//Mat::~Mat(){
//	for (i,this->cols){
//		delete[] this->element[i];
//	}
//	delete[] this->element;
//}
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
	for (i, this->rows){
		for (j, this->cols){
			this->element[i][j] = rand() % 10;
		}
	}
}
_VOID Mat::fill(_INT value){
	for (i, this->rows){
		for (j, this->cols){
			this->element[i][j] = value;
		}
	}
}


//ok
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
//字符串解析
void Mat::strParse(string str){
	_INT rows = 0;
	_INT cols = 0;
	_INT n = 0;
	_INT first;
	while (1){
		if (str.find(";",n)==string::npos){
			break;
		}
		else{
			first = str.find(";");
			n = str.find(";", n)+1;
			rows++;
		}
	}
	for (i, first){
		cout<<str.find(" ", i);
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
//ok
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
//ok
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
		Mat result(this->rows, mat_right.cols);
		result.fill(0);
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