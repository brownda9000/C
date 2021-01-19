CC:=gcc

OPTIONS:=-O2 
LIB_PATH:=-pthread

SRC_DIR:=src
DST_DIR:=bin

default: 
	$(CC) $(OPTIONS) $(LIB_PATH) $(SRC_DIR)/*.c -o $(DST_DIR)/thread1
			   
clean: 
	cd $(DST_DIR); rm thread1
