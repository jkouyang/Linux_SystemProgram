OBJS=add.o sub.o mul.o div.o test.o add.o
TARGET=test
CC=gcc
#$@: 表示目标
#$<: 表示第一个依赖
#$^: 表示所有的依赖
$(TARGET):$(OBJS)
	$(CC) $^ -o $@
test.o:test.c
	$(CC) -c $< -o $@
add.o:add.c
	$(CC) -c $< -o $@ 
sub.o:sub.c
	$(CC) -c $< -o $@ 
mul.o:mul.c
	$(CC) -c $< -o $@ 
div.o:div.c
	$(CC) -c $< -o $@ 
clean:
	rm -rf $(OBJS) $(TARGET)
