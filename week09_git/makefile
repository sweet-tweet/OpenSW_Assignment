PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
OBJ_DIR=$(PROJ_DIR)/obj
INC_DIR=$(PROJ_DIR)/include
BIN_DIR=$(PROJ_DIR)/bin
LIB_DIR=$(PROJ_DIR)/lib

MYAPP=$(BIN_DIR)/myapp
MYAPP_SRC=$(SRC_DIR)/myapp.c
OPS_SRCS=$(filter-out $(MYAPP_SRC), $(wildcard $(SRC_DIR)/*.c))
OPS_OBJS=$(subst $(SRC_DIR), $(OBJ_DIR), $(OPS_SRCS:.c=.o))
OPS_LIB=libmyops.so

LDFLAGS=-L$(LIB_DIR) -lmyops
CFLAGS=-I$(INC_DIR) -lm

CC=gcc
SYMLINK=ln -s

.PHONY: all clean


all: $(MYAPP)

$(MYAPP): $(LIB_DIR)/$(OPS_LIB) $(MYAPP_SRC)
	$(CC) $(MYAPP_SRC) $(LDFLAGS) -o $@ $(CFLAGS)

$(LIB_DIR)/$(OPS_LIB): $(OPS_OBJS)
	$(CC) -fPIC -shared -Wl,-soname=$(OPS_LIB).1 $^ -o $@.1.0
	$(SYMLINK) $(OPS_LIB).1.0 $(LIB_DIR)/$(OPS_LIB).1
	$(SYMLINK) $(OPS_LIB).1 $(LIB_DIR)/$(OPS_LIB)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -fPIC -c $< -o $@ $(CFLAGS)

clean:
	rm -rf $(OBJ_DIR)/* $(LIB_DIR)/* $(BIN_DIR)/*



