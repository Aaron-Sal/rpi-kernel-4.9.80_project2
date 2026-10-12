#include <linux/syscalls.h>
#include <linux/uaccess.h>

SYSCALL_DEFINE4(calc, int, parm1, int, parm2, char, operation, int __user *, result)


{
	int answer;

	if(result == NULL){
		return -1;
	}

	switch(operation){

		case '+':
			answer = parm1 + parm2;
			break;

		case '-':
			answer = parm1 - parm2;
			break;

		case '*':
			answer = parm1 * parm2;
			break;

		case '/':
			if(parm2 == 0) {
				return -1;
			}

			answer = parm1 / parm2;
			break;

		default:
			return -1;
	}

if(copy_to_user(result, &answer, sizeof(answer)) != 0){
	return -1;
	}

	return 0;
}
