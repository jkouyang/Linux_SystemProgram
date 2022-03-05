SRC=$(wildcard *.c)
OBJS=$(patsubst %.c, %.o, $(SRC))
TARGET=test

$(TARGET):$(OBJS)
	gcc $(OBJS) -o $(TARGET) 
%.o:%.c
	gcc -c $< -o $@
$(TARGET):$(OBJS)
	$(CC) $^ -o $@
clean:
	rm -rf $(OBJS) $(TARGET)
