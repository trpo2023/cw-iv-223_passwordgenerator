#make file, install target just places compiled pwGen into $HOME/bin
CC=gcc
DIR=/home/$$USER/bin
MAKE_DIR=$(PWD)

pwGen: $(MAKE_DIR)/Main/pwGen.c
	$(CC) $< -o $@
install:
	make pwGen
	mv pwGen $(DIR)