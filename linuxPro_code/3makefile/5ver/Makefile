OBJS=add.o sub.o mul.o div.o test.o add.o
TARGET=test
CC=gcc
#$@: 表示目标
#$<: 表示第一个依赖
#$^: 表示所有的依赖
$(TARGET):$(OBJS)
	$(CC) $^ -o $@

#模式匹配，所有的.o都依赖于.c
#所有的.c生成对应的.o
%.o:%.c
	$(CC) -c $< -o $@ 
clean:
	rm -rf $(OBJS) $(TARGET)
