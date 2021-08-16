/*
        The MIT License (MIT)

        Copyright (c) 2021 Andrew O'Connell

        Permission is hereby granted, free of charge, to any person obtaining a copy
        of this software and associated documentation files (the "Software"), to deal
        in the Software without restriction, including without limitation the rights
        to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
        copies of the Software, and to permit persons to whom the Software is
        furnished to do so, subject to the following conditions:

        The above copyright notice and this permission notice shall be included in all
        copies or substantial portions of the Software.

        THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
        IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
        FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
        AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
        LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
        OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
        SOFTWARE.

        Dependancies :

        apt-get install libmodbus5 libmodbus-dev

        Compile as below or use 'make all' to allow program to use external system (.so) libraries
        gcc rtu-ai8.c -o rtu-ai8 -lmodbus 


*/

// System includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

// External Libs
#include <modbus/modbus.h> //LGPL 2.1

// Types & Variables
#include "Types.h"

// RTU Module Definitions
#include "adc.c"

// Functions
#include "config.c"
#include "modbus.c"
#include "rtudecode.c"

int main(int argc, char *argv[])
{

	int deviceId = 1;			 // there's only one device in the demo setup
	int displayType = HUMANREAD; // default
	int opt;
	int debugMode = 0;
	int configWrite = 0;
	int adcAverageSetting = 0;
	int modbusBaudSetting = 0;
	int chanResSetting[9] = {0};
	int modeScalar=1; // 4-20ma = x10   0-10V = x5  (see user guide)  default = 1
	int setMaxToZero=0;
	int setMinToZero=0;

	// Load Config, this is
	readConfig();

	// Command line options
	//
	// For reference see : https://azrael.digipen.edu/~mmead/www/Courses/CS180/getopt.html
	//
	// The colon after the letter tells getopt to expect an argument after the option
	// To disable the automatic error printing, put a colon as the first character
	while ((opt = getopt(argc, argv, ":hjcda:b:p:rtxl1:2:3:4:5:6:7:8:v:m:w")) != -1)
	{
		switch (opt)
		{
		case 'h': // Human Readable output
			displayType = HUMANREAD;
			break;
		case 'j': // JSON output
			displayType = JSONREAD;
			break;
		case 'c': // comma seperated output
			displayType = CPUREAD;
			break;
		case 'd': // Print Config
			debugMode = 1;
			break;
		case 'a': // Set modbus address for read
			if (atoi(optarg) > 0 && atoi(optarg) < 255)
			{
				dataSource[deviceId].modbusId = atoi(optarg);
			}
			break;
		case 'b': // Set baudrate for read
			if (atoi(optarg) == 9600 || atoi(optarg) == 14400 || atoi(optarg) == 19200 || atoi(optarg) == 38400 || atoi(optarg) == 57600)
			{
				dataSource[deviceId].baudRate = atoi(optarg);
			}
			break;
		case 'p': // Set serial interface for read
			strcpy(dataSource[deviceId].interface, optarg);
			break;
		case 'w': // Invoke write to RTU NVRAM
			displayType = HUMANREAD;
			configWrite = 1;
			break;
		case 'r': // 4-20mA output display
			modeScalar = 10;
			break;			
		case 't': // 0-10V output display
			modeScalar = 5;
			break;			
		case 'x':
			setMaxToZero=1;
			displayType = HUMANREAD;
			break;
		case 'l':
			setMinToZero=1;
			displayType = HUMANREAD;
			break;	
		case '1': // Configure RTU Channel 1 ADC Resolution setting
			if (atoi(optarg) < 5 && atoi(optarg) > 0)
			{
				chanResSetting[1] = atoi(optarg);
			}
			break;
		case '2': // Configure RTU Channel 2 ADC Resolution setting
			if (atoi(optarg) < 5 && atoi(optarg) > 0)
			{
				chanResSetting[2] = atoi(optarg);
			}
			break;
		case '3': // Configure RTU Channel 3 ADC Resolution setting
			if (atoi(optarg) < 5 && atoi(optarg) > 0)
			{
				chanResSetting[3] = atoi(optarg);
			}
			break;
		case '4': // Configure RTU Channel 4 ADC Resolution setting
			if (atoi(optarg) < 5 && atoi(optarg) > 0)
			{
				chanResSetting[4] = atoi(optarg);
			}
			break;
		case '5': // Configure RTU Channel 5 ADC Resolution setting
			if (atoi(optarg) < 5 && atoi(optarg) > 0)
			{
				chanResSetting[5] = atoi(optarg);
			}
			break;
		case '6': // Configure RTU Channel 6 ADC Resolution setting
			if (atoi(optarg) < 5 && atoi(optarg) > 0)
			{
				chanResSetting[6] = atoi(optarg);
			}
			break;
		case '7': // Configure RTU Channel 7 ADC Resolution setting
			if (atoi(optarg) < 5 && atoi(optarg) > 0)
			{
				chanResSetting[7] = atoi(optarg);
			}
			break;
		case '8': // Configure RTU Channel 8 ADC Resolution setting
			if (atoi(optarg) < 5 && atoi(optarg) > 0)
			{
				chanResSetting[8] = atoi(optarg);
			}
			break;
		case 'v': // Set value for RTU ADC average period register (use in conjunction with -w flag)
			if (atoi(optarg) < 4 && atoi(optarg) > 0)
			{
				adcAverageSetting = atoi(optarg);
			}
			break;
		case 'm': // Set value for RTU Baud Rate register  (use in conjunction with -w flag)
			if (atoi(optarg) < 6 && atoi(optarg) > 0)
			{
				modbusBaudSetting = atoi(optarg);
			}
			break;
		case '?':
			printf("Synapse RTU-AI8 Reader - v1.0\n\n");
			printf("%s [-h|j|c] [-a] [-b] [-p] [-r] [-t] [-1] [-2] [-3] [-4] [-5] [-6] [-7] [-8] [-v] [-m] [-w] [-d]\n\n", argv[0]);
			printf("Syntax :\n\n");
			printf("-h = Human readable output (default)\n");
			printf("-j = JSON readable output\n");
			printf("-c = Comma delimited minimal output\n");
			printf("-r = Output scaled for 4-20mA readings\n");
			printf("-t = Output scaled for 0-10V readings\n");
			printf("\n");
			printf("-x = Reset Max readings (all channels)\n");
			printf("-l = Reset Min readings (all channels)\n");
			printf("\n");
			printf("-a = Set Modbus device address (1-255)                                               - default=1 \n");
			printf("-b = Set serial baud rate (9600/14400/19200/38400/57600)                             - default=19200 \n");
			printf("-p = Set serial interface to use e.g. /dev/ttyS0                                     - default=/dev/ttyUSB0 \n");
			printf("\n");
			printf("-1 = Set Channel 1 ADC channel resolution register (1=12Bit|2=14Bit|3=16Bit|4=18Bit) - default=16Bit\n");
			printf("-2 = Set Channel 2 ADC channel resolution register (1=12Bit|2=14Bit|3=16Bit|4=18Bit) - default=16Bit\n");
			printf("-3 = Set Channel 3 ADC channel resolution register (1=12Bit|2=14Bit|3=16Bit|4=18Bit) - default=16Bit\n");
			printf("-4 = Set Channel 4 ADC channel resolution register (1=12Bit|2=14Bit|3=16Bit|4=18Bit) - default=16Bit\n");
			printf("-5 = Set Channel 5 ADC channel resolution register (1=12Bit|2=14Bit|3=16Bit|4=18Bit) - default=16Bit\n");
			printf("-6 = Set Channel 6 ADC channel resolution register (1=12Bit|2=14Bit|3=16Bit|4=18Bit) - default=16Bit\n");
			printf("-7 = Set Channel 7 ADC channel resolution register (1=12Bit|2=14Bit|3=16Bit|4=18Bit) - default=16Bit\n");
			printf("-8 = Set Channel 8 ADC channel resolution register (1=12Bit|2=14Bit|3=16Bit|4=18Bit) - default=16Bit\n");
			printf("\n");
			printf("-v = Set value for RTU ADC average readings period register (1=4|2=8|3=16)           - default=8 readings\n");
			printf("-m = Set value for RTU Baud Rate register (1=9600/2=14400/3=19200/4=38400/5=57600)  \n");
			printf("\n");
			printf("-w = Confirm writing configured setting registers to RTU NVRAM\n");
			printf("\n");
			printf("-d = debug\n");
			printf("\n");
			printf("Examples :\n");
			printf("Read RTU address 12, baud 38400 output in JSON format          :  %s -j -a 12 -b 38400 -p /dev/ttyS0\n", argv[0]);
			printf("Reconfigure RTU settings for ADC resolution and averaging only :  %s -a 3 -v 1 -1 3 -2 4 -7 2 -w -p /dev/ttyS0\n", argv[0]);
			printf("\n");
			exit(1);
			break;
		}
	}

	if (displayType == HUMANREAD)
	{
		printf("\nSynapse RTU-AI8 Reader - v1.0\n\n");
	}

	// Write
	if (configWrite == 1)
	{
		if (reconfigureADC(deviceId, adcAverageSetting, modbusBaudSetting, chanResSetting) == -1)
		{
			printf("..Fatal Error : Error Reading Modbus device(s) \n\n");
			exit(1);
		}
	}
	


	if (setMinToZero == 1)
	{
		if (resetMinReadings(deviceId) == -1)
		{
			printf("..Fatal Error : Error Reading Modbus device(s) \n\n");
			exit(1);
		}
	}

	if (setMaxToZero == 1)
	{
		if (resetMaxReadings(deviceId) == -1)
		{
			printf("..Fatal Error : Error Reading Modbus device(s) \n\n");
			exit(1);
		}
	}




	if (debugMode == 1)
	{
		printConfig();
	}

	// Read in Modbus registers
	if (displayType == HUMANREAD)
	{
		printf("Modbus Reads...\n");
	}
	if (getModbusValues() == 0)
	{
		if (displayType == HUMANREAD)
		{
			printf("Modbus reads OK\n\n");
		}
	}
	else
	{
		printf("..Fatal Error : Error Reading Modbus device(s) \n\n");
		exit(1);
	}

	// Decode the read in raw modbus ADC values into 12/14/16/18bit floating point readings
	decodeRtuUnits();

	// Print output in desired format
	for (deviceId = 1; deviceId < (config.dsTotal + 1); deviceId++)
	{
		if (displayType == JSONREAD)
		{
			if (deviceId == 1)
				printf("{\n   \"device 1\" : {\n");
			else
				printf("   \"device %i\" : {\n", deviceId);
		}

		displayAdcValues(deviceId, displayType, modeScalar);

		if (displayType == JSONREAD)
		{
			if (deviceId < (config.dsTotal))
				printf("   },\n");
			else
				printf("   }\n}\n", deviceId);
		}
	}
}
