#include<stdio.h>
#include <signal.h>
#include <stdlib.h>

//signal()信号捕获
void signal_handler(int signo){
    if (signo == SIGINT){
        printf("recv SIGINT\n");
    }
    else if (signo == SIGQUIT){
        printf("recv SIGQUIT\n");
    }
}

int main(){
    printf("wait for SIGINT OR SIGQUIT\n");
    // 信号注册函数
    signal(SIGINT, signal_handler);//SIGINT: Ctrl+c.
    signal(SIGQUIT, signal_handler);//SIGQUIT: Ctrl+\.
    while(1);//不让程序结束
    return 0;
}
