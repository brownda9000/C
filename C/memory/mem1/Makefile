CC:=gcc

OPTIONS:=-O0 -ggdb  -pedantic -pg   -Wall  -fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined -fuse-ld=gold  -static-libasan #-fsanitize=memory
LIB_PATH:=-pthread

SRC_DIR:=src
DST_DIR:=bin

default: 
	$(CC) $(OPTIONS) $(LIB_PATH) $(SRC_DIR)/*.c -o $(DST_DIR)/mem1
			   
clean: 
	cd $(DST_DIR); rm mem1
