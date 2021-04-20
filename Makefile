COMPILER = sdcc-sdcc

PROGRAMMER = minipro

SRC_PATH = src/

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
	$(COMPILER) -c $(SRC_PATH)morse.c $(FLAGS)			# Generates .rel file
	$(COMPILER) $(SRC_PATH)main.c morse.rel $(FLAGS)

install:
	$(PROGRAMMER) -p "at89c2051" -w main.ihx

clean:
	rm -f *~
	rm -f main.ihx
	rm -f *.asm *.hex *.rel
	rm -f *.lk *.lst *.map *.mem *.rel *.rst *.sym *.adb *.omf *.cdb *.hashes
