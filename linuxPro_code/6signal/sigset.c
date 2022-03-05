#include<stdio.h>
#include <signal.h>
#include <stdlib.h>
void showset(sigset_t *set){
    int i;
    for (i = 1; i<32; ++i){
        if (sigismember(set, i)){
            printf("1");
        }
        else if (sigismember(set, i) == 0){
            printf("0");
        }
    }
    printf("\n");
}

int main()
{
    //自定义信号集
    sigset_t myset, old;
    sigemptyset(&myset);//清空
    //添加要阻塞的信号
    sigaddset(&myset, SIGINT);
    sigaddset(&myset, SIGQUIT);
    sigaddset(&myset, SIGKILL);
    //自定义信号集设置到内核中的阻塞信号集
    sigprocmask(SIG_BLOCK, &myset, &old);
    sigset_t pend;
    int i = 0;
    while (1){
        // 读内核中的未决信号集的状态
        sigpending(&pend);//将未决信号集读到pend中
        showset(&pend);
        sleep(1);
        i++;
        // 5s之后解除阻塞
        if (i > 5){
            // sigprocmask(SIG_UNBLOCK, &myset, NULL);
            sigprocmask(SIG_SETMASK, &old, NULL);
        }
    }
    return 0;
}
