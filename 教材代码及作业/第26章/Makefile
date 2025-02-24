# ======================
# 工具链配置
# ======================
CC       := gcc
CFLAGS   := -Wall -Wextra -g
LDFLAGS  := -lm

# ======================
# 文件定义
# ======================
TARGET   := t0 t1
SRC      := t0.c t1.c
# OBJ      := $(SRC:.c=.o)

# ======================
# 构建目标
# ======================
.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ======================
# 清理规则
# ======================
clean:
	@echo "清理构建产物..."
	rm -f $(TARGET) $(OBJ)
