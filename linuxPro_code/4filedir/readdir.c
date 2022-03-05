#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<dirent.h>
#include<dirent.h>

int main(){
    DIR *dir=NULL;
    struct dirent *d=NULL;
    //打开目录
    dir=opendir("4filedir");
    if(dir==NULL){
        perror("opendir");
        return -1;
    }
    printf("打开目录成功\n");
    //循环读取目录内容
    while(1){
        d=readdir(dir);
        if(d==NULL)break;
        printf("d_type:%hu d_name:%s\n",d->d_type,d->d_name);
    }
    closedir(dir);
}

