#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

#define __NR_calc 397

int main(void){

	int result;
	long ret;

	ret = syscall(__NR_calc, 20, 8, '-', &result);

	if(ret == 0){
		printf("20 - 8 = %d\n", result);
	}
	else{
		printf("Subtraction failed\n");
	}

	ret = syscall(__NR_calc, 300, 14, '+', &result);

	if(ret == 0){
		printf("300 + 14 = %d\n", result);
	}
	 else {
		printf("Addition failed\n");
	}


	ret = syscall(__NR_calc, 314, 0, '/', &result);

	if(ret != 0){
		printf("314 / 0 correctly failed\n");
	}
	else{
		printf("Division-by-zero test failed\n");
	}

	ret = syscall(__NR_calc, 10, 3, '*', &result);

	if(ret == 0) {
		printf("10 * 3 = %d\n", result);
	}
	 else {
		printf("Multiplication failed\n");
	}

	return 0;
}
