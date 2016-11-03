#include "matrix.h"

Mat::Mat(){
	mat.rows = 0;
	mat.cols = 0;
}
Mat::Mat(_INT rows, _INT cols){
	mat.rows = rows;
	mat.cols = cols;

		mat.x= new _INT*[rows];
	for (_INT i = 0; i <rows; i++){
		mat.x[i] = new _INT[cols];
	}
	srand(10);
	for (_INT i = 0; i < rows; i++){
		for (_INT j = 0; j < cols; j++){
			//用小于255的随机数填充
			mat.x[i][j] = rand()%255;
		}	
	}
}

//矩阵输出
ostream &operator <<(ostream &out, Mat mat_out){
	if (mat_out.mat.rows){
		out << "[" << "\n";
		for (_INT i = 0; i < mat_out.mat.rows; i++){
			for (_INT j = 0; j < mat_out.mat.cols; j++)
				out << mat_out.mat.x[i][j] << " ";
			out << "\n";
		}
		out << "]" << "\n";
	}
	else
		out << "NULL";

	return out;
}
//矩阵加法
Mat Mat::operator+(Mat &mat_right){
	Mat result(mat_right.mat.rows, mat_right.mat.cols);
	for (_INT i = 0; i < result.mat.rows; i++){
		for (_INT j = 0; j < mat.cols; j++){
			result.mat.x[i][j] = mat.x[i][j] + mat_right.mat.x[i][j];
		}
	}
	return result;
}
//矩阵减法
Mat Mat::operator-(Mat &mat_right){
	Mat result(mat_right.mat.rows,mat_right.mat.cols);
	for (_INT i = 0; i < mat_right.mat.rows; i++){
		for (_INT j = 0; j < mat_right.mat.cols;j++){
			result.mat.x[i][j] = mat.x[i][j] - mat_right.mat.x[i][j];
		}
	}
	return result;
}
//深拷贝
Mat Mat::deepcopy(){
	Mat result(mat.rows, mat.cols);
	for (_INT i = 0; i < mat.rows; i++){
		for (_INT j = 0; j < mat.cols; j++){
			result.mat.x[i][j] = mat.x[i][j];
		}
	}
	return result;
}
//赋值
Mat Mat::operator=(Mat &mat_right){
	
}