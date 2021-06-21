COMPILER = sdcc-sdcc

PROGRAMMER = minipro

SRC_PATH = src/
BUILD_PATH = build/

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
	mkdir -p $(BUILD_PATH)
	$(COMPILER) -c $(SRC_PATH)hw_io.c -o $(BUILD_PATH)hw_io.rel $(FLAGS)		# Generates .rel file
	$(COMPILER) -c $(SRC_PATH)morse.c -o $(BUILD_PATH)morse.rel $(FLAGS)		# Generates .rel file
	$(COMPILER) -c $(SRC_PATH)tests.c -o $(BUILD_PATH)tests.rel $(FLAGS)		# Generates .rel file
	$(COMPILER) -c $(SRC_PATH)hw_timer0.c -o $(BUILD_PATH)hw_timer0.rel $(FLAGS)	# Generates .rel file
	$(COMPILER) $(SRC_PATH)main.c $(BUILD_PATH)morse.rel $(BUILD_PATH)hw_timer0.rel $(BUILD_PATH)tests.rel $(BUILD_PATH)hw_io.rel -o $(BUILD_PATH)main.ihx $(FLAGS)

install:
	$(PROGRAMMER) -p "AT89C2051@DIP20" -w $(BUILD_PATH)main.ihx

clean:
	rm -f $(SRC_PATH)*~
	rm -Rf $(BUILD_PATH)
