# Neutec Repeater Controller Firmware

This repository contains the firmware for the microcontroller, AT89C2051, used
in the Neutec Repeater Controller Board. 

The `master` branch has the code for the VHF repeater (CQ0VBRG) while
the `ChangesRUGuimaraes` branch has the code for the UHF Repeater (CQ0UGMR).

## Differences
The UHF repeater uses a 4 MHz xtal and the VHF repeater uses a 24 MHz xtal.
The VHF repeater monitors the PTT line, the UHF one does not.

## Requirements

The project uses [sdcc - Small Devices C Compiler](http://sdcc.sourceforge.net/)
to compile and a [TL866II Plus](http://www.autoelectric.cn/en/tl866_main.html)
programmer was used to flash the binary using 
[minipro (linux)](https://gitlab.com/DavidGriffith/minipro/) application.

## Build

Just use `make` to compile and `make install`to flash the code using the
programmer.

## Hardware

The hardware information is available 
[here](https://github.com/phastmike/neutec-repeater-hardware).
