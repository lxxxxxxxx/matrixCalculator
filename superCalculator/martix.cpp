#include "matrix.h"

template <typename TY1>
Mat<TY1>::Mat(){
	this->rows = 0;
	this->cols = 0;
	this->element = _NEW TY1*[rows];
	_FOR(i, rows){
		this->element[i] = _NEW TY1[cols];
	}
	_FOR(i, rows){
		_FOR(j, cols){
			this->element[i][j] = rand() % 10;
		}
	}
}

template <typename TY1>
Mat<TY1>::Mat(_INT rows, _INT cols){
	this->rows = rows;
	this->cols = cols;
	this->element = _NEW TY1*[rows];
	_FOR(i, rows){
		this->element[i] = _NEW TY1[cols];
	}
	_FOR(i, rows){
		_FOR(j, cols){
			this->element[i][j] = rand() % 10;
		}
	}
}

template <typename TY1>
Mat<TY1>::Mat(_INT rows, _INT cols, TY1 value){
	this->rows = rows;
	this->cols = cols;
	this->element = _NEW TY1*[rows];
	_FOR(i, rows){
		this->element[i] = _NEW TY1[cols];
	}
	_FOR(i, rows){
		_FOR(j, cols){
			this->element[i][j] = value;
		}	
	}
}

template <typename TY1>
Mat<TY1>::Mat(string str){
	*this=strParse(str);
}

template <typename TY1>
Mat<TY1>::~Mat(){
	//cout << "析构" << endl;
	_FOR (i,this->rows){
		delete[] this->element[i];
	}
	delete[] this->element;
}

template <typename TY1>
_INT Mat<TY1>::getRows(){
	return this->rows;
}

template <typename TY1>
_INT Mat<TY1>::getCols(){
	return this->cols;
}

//fill mat   ok
template <typename TY1>
Mat<TY1> &Mat<TY1>::fill(){
	srand(10);
	_FOR(i, this->rows){
		_FOR(j, this->cols){
			this->element[i][j] = rand() % 10;
		}
	}
	return *this;
}
template <typename TY1>
Mat<TY1> &Mat<TY1>::fill(_INT value){
	_FOR(i, this->rows){
		_FOR(j, this->cols){
			this->element[i][j] = value;
		}
	}
	return *this;
}
//output    ok
template <typename TY1>
ostream &operator <<(ostream &out, const Mat<TY1> &mat_out){
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
//parse string to a mat     ok
template <typename TY1>
Mat<TY1> Mat<TY1>::strParse(string &str){
	std::vector<std::string> subs;
	int pos;
	_FOR (i,str.length()){
		pos = str.find(";", i);
		string s = str.substr(i, pos - i);
		subs.push_back(s);
		if (pos == str.npos)
			break;
		else
			i = pos;
	}
	std::vector<string> *datas = _NEW std::vector<string>[subs.size()];
	int n = 0;
	_FOR(i,subs.size()){
		string temp = subs.at(i);
		_FOR(j,temp.length()){
			n = temp.find(' ', j);
			string sub = temp.substr(j, n - j);
			datas[i].push_back(sub);
			if (n == str.npos)
				break;
			else
				j = n;
		}
	}
	Mat<TY1> mat(subs.size(), datas[0].size());
	for (int i = 0; i < subs.size(); i++){
		for (int j = 0; j < datas[i].size(); j++){
			mat.element[i][j] = atoi(datas[i].at(j).c_str());
		}
	}
	delete[] datas;
	return mat;
}
//mat add     ok
template <typename TY1>
Mat<TY1> Mat<TY1>::operator+(const Mat &mat_right){
	if (!(this->rows == mat_right.rows&&this->cols == mat_right.cols)){
		std::cout << "the nubmers of lines and columns of two matrixs should be identical." << endl;
		Mat<TY1> mat_null(0, 0);
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
//mat subtraction     ok
template <typename TY1>
Mat<TY1> Mat<TY1>::operator-(const Mat<TY1> &mat_right){
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
//deep copy    ok
template <typename TY1>
_VOID Mat<TY1>::deepcopy(const Mat<TY1> &mat_original){
	this->rows = mat_original.rows;
	this->cols = mat_original.cols;
	this->element = _NEW _INT*[mat_original.rows];
	_FOR(i, mat_original.rows){
		this->element[i] = _NEW _INT[mat_original.cols];
	}
	_FOR(i, mat_original.rows){
		_FOR(j, mat_original.cols){
			this->element[i][j] = mat_original.element[i][j];
		}
	}
}
//copy constraction   ok
template <typename TY1>
Mat<TY1>::Mat(Mat<TY1> &mat_right){
	//cout << "调用了拷贝构造函数" << endl;
	deepcopy(mat_right);
}
//assignment    ok
template <typename TY1>
Mat<TY1> &Mat<TY1>::operator=(Mat<TY1> &mat_right){
	//std::cout << "调用了赋值运算符" << endl;
	deepcopy(mat_right);
	return *this;
}



//multiplication    ok
template <typename TY1>
Mat<TY1> Mat<TY1>::operator*(const Mat<TY1> &mat_right){
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
//transposition
template <typename TY1>
Mat<TY1> Mat<TY1>::transposition(){
	Mat mat_trans(this->cols, this->rows);
	_FOR(i, this->rows){
		_FOR(j, this->cols){
			mat_trans.element[j][i] = this->element[i][j];
		}
	}
	return mat_trans;
}