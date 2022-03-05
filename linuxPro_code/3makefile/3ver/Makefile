#变量
OBJS=test.o add.o sub.o mul.o div.o
all:$(OBJS)
	gcc $(OBJS)
	
test.o:test.c
	gcc -c test.c
add.o:add.c
	gcc -c add.c
sub.o:sub.c
	gcc -c sub.c
mul.o:mul.c
	gcc -c mul.c
div.o:div.c
	gcc -c div.c
clean:
	rm -rf $(OBJS) a.out
