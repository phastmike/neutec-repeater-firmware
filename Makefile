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
	$(COMPILER) -c morse.c $(FLAGS)			# Generates .rel file
	$(COMPILER) main.c morse.rel $(FLAGS)

install:
	$(PROGRAMMER) -p "at89c2051" -w main.ihx

clean:
	rm *~
	rm *.rel
	rm main.ihx
