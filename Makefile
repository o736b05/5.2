# основные настройки
TARGET = main
CC = gcc
CFLAGS = -Wall -Iinclude

# определение ос
ifeq ($(OS),Windows_NT)
    # Windows
    LIB_PREFIX = lib
    LIB_EXT = .dll
    EXE_EXT = .exe
    LDFLAGS = -L./exe -lload
else
    # Linux/Unix
    LIB_PREFIX = lib
    LIB_EXT = .so
    EXE_EXT =
    LDFLAGS = -L./exe -lload -Wl,-rpath,'$$ORIGIN'
endif

# названия директорий
SRC_DIR = src/
OBJ_DIR = obj/
LIB_DIR = lib/
EXE_DIR = exe/

# основная цель
all: $(EXE_DIR)$(TARGET)$(EXE_EXT)

$(EXE_DIR)$(TARGET)$(EXE_EXT): $(OBJ_DIR)main.o $(EXE_DIR)$(LIB_PREFIX)load$(LIB_EXT) $(EXE_DIR)$(LIB_PREFIX)arrayfunc$(LIB_EXT) $(EXE_DIR)$(LIB_PREFIX)matrixfunc$(LIB_EXT)
	$(CC) $(CFLAGS) -o $@ $(OBJ_DIR)main.o $(LDFLAGS)

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
	$(CC) -shared -o $@ $< $(LDFLAGS)

$(EXE_DIR)$(LIB_PREFIX)arrayfunc$(LIB_EXT): $(OBJ_DIR)arrayfunc.o
	@mkdir -p $(EXE_DIR)
	$(CC) -shared -o $@ $<

$(EXE_DIR)$(LIB_PREFIX)matrixfunc$(LIB_EXT): $(OBJ_DIR)matrixfunc.o
	@mkdir -p $(EXE_DIR)
	$(CC) -shared -o $@ $<

clean:
	rm -rf $(OBJ_DIR) $(EXE_DIR)

.PHONY: all clean
