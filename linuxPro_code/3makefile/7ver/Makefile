SRC=$(wildcard *.c)
OBJS=$(patsubst %.c, %.o, $(SRC))
TARGET=test

$(TARGET):$(OBJS)
	@gcc $(OBJS) -o $(TARGET) 
%.o:%.c
	@gcc -c $< -o $@
.PHONY:clean
clean:
	@rm -rf $(OBJS) $(TARGET)
