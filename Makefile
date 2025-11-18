# Настройки компилятора
TARGET = main
CC = gcc
CFLAGS = -Wall -Iinclude

# Пути
SRC_DIR = src/
OBJ_DIR = obj/
EXE_DIR = exe/

# Linux/Unix
DLL_EXT = .so
LIB_PREFIX = lib
LIB_EXT = .so
LDFLAGS = -L./exe -lload# -Wl,-rpath,'$$ORIGIN' -ldl

# Правила сборки
all: $(EXE_DIR)$(TARGET)

$(EXE_DIR)$(TARGET) : $(OBJ_DIR)main.o $(EXE_DIR)$(LIB_PREFIX)load$(LIB_EXT) $(EXE_DIR)$(LIB_PREFIX)arrayfunc$(LIB_EXT) $(EXE_DIR)$(LIB_PREFIX)matrixfunc$(LIB_EXT)
	$(CC) -o $@ $(OBJ_DIR)main.o -L./exe/ -lload

$(OBJ_DIR)main.o: $(SRC_DIR)main.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)load.o: $(SRC_DIR)load.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -fPIC -o $@ $<

$(OBJ_DIR)arrayfunc.o: $(SRC_DIR)arrayfunc.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -fPIC -o $@ $<

$(OBJ_DIR)matrixfunc.o: $(SRC_DIR)matrixfunc.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -fPIC -o $@ $<

$(EXE_DIR)$(LIB_PREFIX)load$(LIB_EXT): $(OBJ_DIR)load.o
	@mkdir -p $(EXE_DIR)
	$(CC) -shared -o $@ $< -ldl

$(EXE_DIR)$(LIB_PREFIX)arrayfunc$(LIB_EXT): $(OBJ_DIR)arrayfunc.o
	@mkdir -p $(EXE_DIR)
	$(CC) -shared -o $@ $<

$(EXE_DIR)$(LIB_PREFIX)matrixfunc$(LIB_EXT): $(OBJ_DIR)matrixfunc.o
	@mkdir -p $(EXE_DIR)
	$(CC) -shared -o $@ $<

clean:
	rm -rf $(OBJ_DIR) $(EXE_DIR)

.PHONY: all clean
