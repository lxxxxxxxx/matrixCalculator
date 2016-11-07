#include "common.h"

_ENUM matrixType{
	UNIT_MATRIX = 0,//单位矩阵
	DIAGONAL_MATRIX,//对角矩阵
	UPPER_TRIANGULAR_MATRIX,//上三角矩阵
	LOWER_TRIANGULAR_MATRIX,//下三角矩阵
	VALUE_FILL_MATRIX,//用value填充
	RAND_FILL_MATRIX,//用随机数填充
};