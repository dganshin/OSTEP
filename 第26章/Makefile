CC = gcc
CFLAGS = -Wall -g  # 显示所有警告，包含调试信息
LDFLAGS = -lm      # 如果需要数学库

TARGET = myprogram  # 生成的可执行文件名
SRC = myprogram.c   # 源文件

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f $(TARGET) *.o

.PHONY: all clean
