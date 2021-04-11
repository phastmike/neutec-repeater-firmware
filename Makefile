COMPILER = sdcc-sdcc

PROGRAMMER = minipro

FLAGS = -mmcs51\
		  --iram-size 128 \
		  --xram-size 0 \
		  --code-size 2048 \
		  --nooverlay \
		  --noinduction \
		  --verbose \
		  --debug \
		  -V \
		  --std-sdcc99 \
		  --model-small

all:
	$(COMPILER) main.c $(FLAGS)

install:
	$(PROGRAMMER) -p "at89c2051" -w main.ihx
