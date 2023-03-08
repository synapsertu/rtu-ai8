# Synapse RTU-AI8 Tool

Dependancies :

```# apt-get install libmodbus5 libmodbus-dev```

Compile as below or use 'make all' 

```# gcc rtu-ai8.c -o rtu-ai8 -lmodbus ```


Sample syntax 

```
Synapse RTU-AI8 Reader - v1.3

./rtu-ai8 [-h|j|c] [-a?] [-b?] [-p?] [-r|t] [-1?] [-2?] [-3?] [-4?] [-5?] [-6?] [-7?] [-8?] [-v?] [-m?] [-w] [-q?] [-y] [-d]

Syntax :

-h = Human readable output (default)
-j = JSON readable output
-c = Comma delimited minimal output
-r = Output scaled for 4-20mA readings
-t = Output scaled for 0-10V readings

-x = Reset Max readings (all channels)
-l = Reset Min readings (all channels)

-a = Set Modbus device address (1-255)                                               - default=1
-b = Set serial baud rate (9600/14400/19200/38400/57600)                             - default=19200
-p = Set serial interface to use e.g. /dev/ttyS0                                     - default=/dev/ttyUSB0

-1 = Set Channel 1 ADC channel resolution register (1=12Bit|2=14Bit|3=16Bit|4=18Bit) - default=16Bit
-2 = Set Channel 2 ADC channel resolution register (1=12Bit|2=14Bit|3=16Bit|4=18Bit) - default=16Bit
-3 = Set Channel 3 ADC channel resolution register (1=12Bit|2=14Bit|3=16Bit|4=18Bit) - default=16Bit
-4 = Set Channel 4 ADC channel resolution register (1=12Bit|2=14Bit|3=16Bit|4=18Bit) - default=16Bit
-5 = Set Channel 5 ADC channel resolution register (1=12Bit|2=14Bit|3=16Bit|4=18Bit) - default=16Bit
-6 = Set Channel 6 ADC channel resolution register (1=12Bit|2=14Bit|3=16Bit|4=18Bit) - default=16Bit
-7 = Set Channel 7 ADC channel resolution register (1=12Bit|2=14Bit|3=16Bit|4=18Bit) - default=16Bit
-8 = Set Channel 8 ADC channel resolution register (1=12Bit|2=14Bit|3=16Bit|4=18Bit) - default=16Bit

-v = Set value for RTU ADC average readings period register (1=4|2=8|3=16)           - default=8 readings
-m = Set value for RTU Baud Rate register (1=9600/2=14400/3=19200/4=38400/5=57600)   - default=3

-q = Set RTU unit to ouput raw ADC readings mode on/off (1=off/2=on)                 - default=1
-y = decode raw ADC values

-w = Confirm writing configured setting registers to RTU NVRAM

-d = debug

Examples :
Read RTU address 12, baud 38400 output in JSON format          :  ./rtu-ai8 -j -a 12 -b 38400 -p /dev/ttyS0
Reconfigure RTU settings for ADC resolution and averaging only :  ./rtu-ai8 -a 3 -v 1 -1 3 -2 4 -7 2 -w -p /dev/ttyS0


```
