# Makefile for ush
#
# MakeFile for HOT POTATO
# 
CC=gcc
SRC=player.c
SRC1=master.c
CALL= player master
TARSRC= player.c master.c

all: player master

player:	$(SRC) 
	$(CC) $(SRC) -o player
	

master: $(SRC1)
	$(CC) $(SRC1) -o master

tar:
	tar czvf potato.tar.gz $(TARSRC) Makefile README

clean:
	\rm $(CALL)
