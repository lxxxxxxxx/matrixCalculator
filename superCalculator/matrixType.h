#include "common.h"

_ENUM matrixType{
	UNIT_MATRIX = 0,//��λ����
	DIAGONAL_MATRIX,//�ԽǾ���
	UPPER_TRIANGULAR_MATRIX,//�����Ǿ���
	LOWER_TRIANGULAR_MATRIX,//�����Ǿ���
	VALUE_FILL_MATRIX,//��value���
	RAND_FILL_MATRIX,//����������
};