COMPILER = sdcc-sdcc

PROGRAMMER = minipro

all:
	$(COMPILER) main.c 

install:
	$(PROGRAMMER) -p"at89c2051" -w main.ihx
