#include "testOperator.h"
#include <stdarg.h>

void testVa(int a, ...){
	va_list arg_ptr;
	va_start(arg_ptr, a);
	cout << va_arg(arg_ptr, int);
	cout << va_arg(arg_ptr, int);
}


int main(){
	//testVa(1, 2, 3);
	/*Mat *mat;
	cout << *mat;*/
	testMatrixFirstStage();
	return 0;
}