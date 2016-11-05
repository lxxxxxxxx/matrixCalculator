#include "matrix.h"

Mat::Mat(){
	this->rows = 0;
	this->cols = 0;
}
Mat::Mat(_INT rows, _INT cols){
	this->rows = rows;
	this->cols = cols;

	this->element = new _INT*[rows];
	for (_INT i = 0; i <rows; i++){
		this->element[i] = new _INT[cols];
	}
	srand(10);
	for (_INT i = 0; i < rows; i++){
		for (_INT j = 0; j < cols; j++){
			//��С��255����������
			this->element[i][j] = rand() % 255;
		}	
	}
}
//Mat::~Mat(){
//	for (_INT i = 0; i < this->cols; i++){
//		delete[] this->element[i];
//	}
//	delete[] this->element;
//}

//�������
ostream &operator <<(ostream &out, const Mat &mat_out){
	if (mat_out.rows==0||mat_out.cols==0)
		out << "[\nNULL\n]";
	else
	{
		out << "[" << "\n";
		for (_INT i = 0; i < mat_out.rows; i++){
			for (_INT j = 0; j < mat_out.cols; j++)
				out << mat_out.element[i][j] << " ";
			out << "\n";
		}
		out << "]" << "\n";
	}

		

	return out;
}
//����ӷ�
Mat &Mat::operator+(const Mat &mat_right){
	if (!(this->rows == mat_right.rows&&this->cols == mat_right.cols)){
		std::cout << "the nubmers of lines and columns of two matrixs should be identical." << endl;
		Mat mat_null(0,0);
		return mat_null;
	}
	else{
		Mat result(mat_right.rows, mat_right.cols);
		for (_INT i = 0; i < this->rows; i++){
			for (_INT j = 0; j < this->cols; j++){
				result.element[i][j] = this->element[i][j] + mat_right.element[i][j];
			}
		}
		return result;
	}
	
}
//�������
Mat Mat::operator-(const Mat &mat_right){
	if (!(this->rows == mat_right.rows&&this->rows == mat_right.cols)){
		std::cout << "\nthe nubmers of lines and columns of two matrixs should be identical." << endl;
		Mat mat_return(0, 0);
		return mat_return;
	}
	else{
		Mat result(mat_right.rows, mat_right.cols);
		for (_INT i = 0; i < this->rows; i++){
			for (_INT j = 0; j < this->cols; j++){
				result.element[i][j] = this->element[i][j] - mat_right.element[i][j];
			}
		}
		return result;
	}
	
}
//���
_VOID Mat::deepcopy(Mat &mat_original){
	this->rows = mat_original.rows;
	this->cols = mat_original.cols;
	this->element = new _INT*[mat_original.rows];
	for (_INT i = 0; i < mat_original.rows; i++){
		this->element[i] = new _INT[mat_original.cols];
	}
	for (_INT i = 0; i < mat_original.rows; i++){
		for (_INT j = 0; j < mat_original.cols; j++){
			this->element[i][j] = mat_original.element[i][j];
		}
	}
}
//��������
Mat::Mat(Mat &mat_right){
	cout << "�����˿������캯��" << endl;
	deepcopy(mat_right);
}
//��ֵ
Mat Mat::operator=(Mat &mat_right){
	std::cout << "�����˸�ֵ�����" << endl;
	deepcopy(mat_right);
	return *this;
}
//�˷�
//Mat operator*(const Mat &mat_right){
//	return;
//}