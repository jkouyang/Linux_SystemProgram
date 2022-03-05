#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
    pid_t pid =-1;
    int status=0;
    int i;
    pid =fork();
    if(pid==0){//子进程
        for(i=0;i<5;i++){
            printf("child process %d do sth %d\n",getpid(),i+1);
            sleep(5);
        }
        exit(10);
    }
    //父进程
    printf("父进程等待子进程结束，回收其资源\n");
    wait(&status);
    //正常退出
    if(WIFEXITED(status)){
        printf("子进程退出状态码%d\n",WEXITSTATUS(status));
    }
    //子进程被杀死
    else if(WIFSIGNALED(status)){
        printf("子进程被信号%d杀死\n",WTERMSIG(status));
    }
    else if(WIFSTOPPED(status)){
        printf("子进程被信号：%d中断\n",WSTOPSIG(status));
    }
    return 0;
}

