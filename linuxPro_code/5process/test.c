#include<stdio.h>
#include<unistd.h>
int main(){
    printf("hello itcast\n");
    //arg0 arg1 arg2 ... argn
    //arg0一般是可执行文件名，argn必须为NULL
    //等价执行 ls -l /home
    execlp("ls","ls","-l","/home",NULL);
    printf("hello world");              
}
