#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
	int pid = fork();

    if(pid ==0){
        printf("\nChild Process\n");
        printf("\nChild Process is is %d",getpid());
        printf("\nIts parent process id is %d",getppid());
        sleep(2);

        printf("\nChild process after sleep = 5\n");
        printf("\nChild process id is %d",getpid());
        printf("\nIts parent process id is %d",getppid());

    }
    else{
        printf("\n\nParent process");
        sleep(5);
        printf("\nChild Process id is %d", getpid());
        printf("\nIts parent proces id is %d\n", getppid());

    }
}
