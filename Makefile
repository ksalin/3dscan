CC=gcc

all: 3dscan

3dscan: 3dscan.c config.h
	$(CC) 3dscan.c -o 3dscan -lwiringPi
	./owner.sh

install: 3dscan
	sudo cp -vf 3dscan /usr/local/bin
clean:
	rm -f 3dscan *.o
