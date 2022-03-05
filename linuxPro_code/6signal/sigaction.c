#include<stdio.h>
#include <signal.h>
#include <stdlib.h>

//sigaction()信号捕获
void myfunc(int signo){
    printf("捕获 SIGINT：%d\n",signo);
}

int main(){
    printf("wait for SIGINT OR SIGQUIT\n");
    // 信号注册函数
    struct sigaction act;
    act.sa_flags = 0;
    act.sa_handler = myfunc;
    sigemptyset(&act.sa_mask);//清空阻塞
    //并不是进程阻塞ctrl+反斜杠，而是在捕获ctrl+c的过程中阻塞ctrl+反斜杠
    sigaddset(&act.sa_mask, SIGQUIT);//添加阻塞crtl+反斜杠
    sigaction(SIGINT, &act, NULL);//捕获SIGINT: Ctrl+c.
    while(1);//不让程序结束
    return 0;
}
