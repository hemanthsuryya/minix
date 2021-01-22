#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<time.h>

int main(){
	char str[] = "Hello world";
	for(int i =0; i<strlen(str); i++){
		int rc = fork();
		int randtime;
		if(rc ==0){
			printf("%c (PID:%d) (Parent PID:%d) \n", str[i], (int) getpid(), (int) getppid());
			randtime = 1+rand() %4;
			sleep(randtime);
		}else{
			wait(NULL);
			exit(0);
		}
	}
	return 0;
}

