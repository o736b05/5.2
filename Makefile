TARGET = main
CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = -L./exe -lload

# поддержка Windows
DLL_EXT = .dll
EXE_EXT = .exe

# названия директорий
SRC_DIR = src/
OBJ_DIR = obj/
EXE_DIR = exe/

# основная цель
all: $(EXE_DIR)$(TARGET)$(EXE_EXT)

$(EXE_DIR)$(TARGET)$(EXE_EXT): $(OBJ_DIR)main.o $(EXE_DIR)load$(DLL_EXT) $(EXE_DIR)arrayfunc$(DLL_EXT) $(EXE_DIR)matrixfunc$(DLL_EXT)
	$(CC) -o $@ $(OBJ_DIR)main.o $(LDFLAGS)

$(OBJ_DIR)main.o: $(SRC_DIR)main.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)load.o: $(SRC_DIR)load.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)arrayfunc.o: $(SRC_DIR)arrayfunc.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)matrixfunc.o: $(SRC_DIR)matrixfunc.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXE_DIR)load$(DLL_EXT): $(OBJ_DIR)load.o
	@mkdir -p $(EXE_DIR)
	$(CC) -shared -o $@ $<

$(EXE_DIR)arrayfunc$(DLL_EXT): $(OBJ_DIR)arrayfunc.o
	@mkdir -p $(EXE_DIR)
	$(CC) -shared -o $@ $<

$(EXE_DIR)matrixfunc$(DLL_EXT): $(OBJ_DIR)matrixfunc.o
	@mkdir -p $(EXE_DIR)
	$(CC) -shared -o $@ $<

clean:
	rm -rf $(OBJ_DIR) $(EXE_DIR)

.PHONY: all clean
