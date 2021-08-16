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
		
		int numRegisters;				//  Total number of registers enabled to scan fr
		int ChanMode[8];				//  Per-chan mode, this gives the chan setting or mode e.g.ADC this is the resolution setting for Digin this the chan mode 
		int regAddress[MAX_DATAPOINTS]; //  addess minus the 40000 multiier, total  max registers per device              	
		float value[MAX_DATAPOINTS];	// 	decoded (and then scaled) value for the register	
		
		
		
*/	

	

void displayAdcValues(int deviceId, int displayType, int modeScalar)
{
	int regId;
	const char *adcRes[5];
				adcRes[0] = "16Bit";
				adcRes[1] = "12Bit";
				adcRes[2] = "14Bit";
				adcRes[3] = "16Bit";
				adcRes[4] = "18Bit";

	// initialise these to zero or else we'll get nonsense readings 
	// shown if the chan/register is not enabled in the config.
	// You could initialise this to NaN or some other recognisable value to indicate "No reading available" 
	float chanLve[9]={0.0};
	float chanMax[9]={0.0};
	float chanMin[9]={0.0};
	float chanAvg[9]={0.0};
	

	for(regId=1 ; regId<(dataSource[deviceId].numRegisters+1) ; regId++)
	{	
		// Deals with chan 1 value registers
		if ( dataSource[deviceId].regAddress[regId] == 1  ) { chanLve[1]=(dataSource[deviceId].value[regId] * modeScalar); }
		if ( dataSource[deviceId].regAddress[regId] == 17 ) { chanAvg[1]=(dataSource[deviceId].value[regId] * modeScalar); }
		if ( dataSource[deviceId].regAddress[regId] == 33 ) { chanMax[1]=(dataSource[deviceId].value[regId] * modeScalar); }
		if ( dataSource[deviceId].regAddress[regId] == 49 ) { chanMin[1]=(dataSource[deviceId].value[regId] * modeScalar); }
		
		// Deals with chan 2 value registers
		if ( dataSource[deviceId].regAddress[regId] == 3  ) { chanLve[2]=(dataSource[deviceId].value[regId] * modeScalar); }
		if ( dataSource[deviceId].regAddress[regId] == 19 ) { chanAvg[2]=(dataSource[deviceId].value[regId] * modeScalar); }
		if ( dataSource[deviceId].regAddress[regId] == 35 ) { chanMax[2]=(dataSource[deviceId].value[regId] * modeScalar); }
		if ( dataSource[deviceId].regAddress[regId] == 51 ) { chanMin[2]=(dataSource[deviceId].value[regId] * modeScalar); }
		
		// Deals with chan 3 value registers
		if ( dataSource[deviceId].regAddress[regId] == 5  ) { chanLve[3]=(dataSource[deviceId].value[regId] * modeScalar); }
		if ( dataSource[deviceId].regAddress[regId] == 21 ) { chanAvg[3]=(dataSource[deviceId].value[regId] * modeScalar); }
		if ( dataSource[deviceId].regAddress[regId] == 37 ) { chanMax[3]=(dataSource[deviceId].value[regId] * modeScalar); }
		if ( dataSource[deviceId].regAddress[regId] == 53 ) { chanMin[3]=(dataSource[deviceId].value[regId] * modeScalar); }

		// Deals with chan 4 value registers
		if ( dataSource[deviceId].regAddress[regId] == 7  ) { chanLve[4]=(dataSource[deviceId].value[regId] * modeScalar); }
		if ( dataSource[deviceId].regAddress[regId] == 23 ) { chanAvg[4]=(dataSource[deviceId].value[regId] * modeScalar); }
		if ( dataSource[deviceId].regAddress[regId] == 39 ) { chanMax[4]=(dataSource[deviceId].value[regId] * modeScalar); }
		if ( dataSource[deviceId].regAddress[regId] == 55 ) { chanMin[4]=(dataSource[deviceId].value[regId] * modeScalar); }
		
		// Deals with chan 5 value registers
		if ( dataSource[deviceId].regAddress[regId] == 9  ) { chanLve[5]=(dataSource[deviceId].value[regId] * modeScalar); }
		if ( dataSource[deviceId].regAddress[regId] == 25 ) { chanAvg[5]=(dataSource[deviceId].value[regId] * modeScalar); }
		if ( dataSource[deviceId].regAddress[regId] == 41 ) { chanMax[5]=(dataSource[deviceId].value[regId] * modeScalar); }
		if ( dataSource[deviceId].regAddress[regId] == 57 ) { chanMin[5]=(dataSource[deviceId].value[regId] * modeScalar); }

		// Deals with chan 6 value registers
		if ( dataSource[deviceId].regAddress[regId] == 11 ) { chanLve[6]=(dataSource[deviceId].value[regId] * modeScalar); }
		if ( dataSource[deviceId].regAddress[regId] == 27 ) { chanAvg[6]=(dataSource[deviceId].value[regId] * modeScalar); }
		if ( dataSource[deviceId].regAddress[regId] == 43 ) { chanMax[6]=(dataSource[deviceId].value[regId] * modeScalar); }
		if ( dataSource[deviceId].regAddress[regId] == 59 ) { chanMin[6]=(dataSource[deviceId].value[regId] * modeScalar); }

		// Deals with chan 7 value registers
		if ( dataSource[deviceId].regAddress[regId] == 13 ) { chanLve[7]=(dataSource[deviceId].value[regId] * modeScalar); }
		if ( dataSource[deviceId].regAddress[regId] == 29 ) { chanAvg[7]=(dataSource[deviceId].value[regId] * modeScalar); }
		if ( dataSource[deviceId].regAddress[regId] == 45 ) { chanMax[7]=(dataSource[deviceId].value[regId] * modeScalar); }
		if ( dataSource[deviceId].regAddress[regId] == 61 ) { chanMin[7]=(dataSource[deviceId].value[regId] * modeScalar); }

		// Deals with chan 8 value registers
		if ( dataSource[deviceId].regAddress[regId] == 15 ) { chanLve[8]=(dataSource[deviceId].value[regId] * modeScalar); }
		if ( dataSource[deviceId].regAddress[regId] == 31 ) { chanAvg[8]=(dataSource[deviceId].value[regId] * modeScalar); }
		if ( dataSource[deviceId].regAddress[regId] == 47 ) { chanMax[8]=(dataSource[deviceId].value[regId] * modeScalar); }
		if ( dataSource[deviceId].regAddress[regId] == 63 ) { chanMin[8]=(dataSource[deviceId].value[regId] * modeScalar); }	
	} 
	
	
	
	// present the output in the format desired by the command line option
	if (displayType == HUMANREAD)
	{		
	
		printf("_____| AI8 Modbus Address %i |______________________________________________________________________\n", dataSource[deviceId].modbusId);
		printf("Ch\tResolution\tLive\t\tMin\t\tAvg\t\tMax\n");
		printf("1\t%s\t\t%f\t%f\t%f\t%f\n", adcRes[dataSource[deviceId].ChanMode[1]],chanLve[1],chanMin[1],chanAvg[1],chanMax[1]);
		printf("2\t%s\t\t%f\t%f\t%f\t%f\n", adcRes[dataSource[deviceId].ChanMode[2]],chanLve[2],chanMin[2],chanAvg[2],chanMax[2]);
		printf("3\t%s\t\t%f\t%f\t%f\t%f\n", adcRes[dataSource[deviceId].ChanMode[3]],chanLve[3],chanMin[3],chanAvg[3],chanMax[3]);		
		printf("4\t%s\t\t%f\t%f\t%f\t%f\n", adcRes[dataSource[deviceId].ChanMode[4]],chanLve[4],chanMin[4],chanAvg[4],chanMax[4]);
		printf("5\t%s\t\t%f\t%f\t%f\t%f\n", adcRes[dataSource[deviceId].ChanMode[5]],chanLve[5],chanMin[5],chanAvg[5],chanMax[5]);
		printf("6\t%s\t\t%f\t%f\t%f\t%f\n", adcRes[dataSource[deviceId].ChanMode[6]],chanLve[6],chanMin[6],chanAvg[6],chanMax[6]);
		printf("7\t%s\t\t%f\t%f\t%f\t%f\n", adcRes[dataSource[deviceId].ChanMode[7]],chanLve[7],chanMin[7],chanAvg[7],chanMax[7]);
		printf("8\t%s\t\t%f\t%f\t%f\t%f\n", adcRes[dataSource[deviceId].ChanMode[8]],chanLve[8],chanMin[8],chanAvg[8],chanMax[8]);
		printf("\n\n");
	}
	
	if (displayType == JSONREAD)
	{		
		printf ("      \"name\":\"RTU-AI8\",\n");
		printf ("      \"type\": %i,\n",dataSource[deviceId].deviceType);
		printf ("      \"deviceId\":\"%i\",\n",deviceId);
		printf ("      \"modbusId\":\"%i\",\n",dataSource[deviceId].modbusId);	
		printf ("      \"channels\": 8,\n");

		for(int chanNo=1 ; chanNo <9 ; chanNo++)
		{				
			printf ("      \"channel %i\": {\n",chanNo);
			printf ("         \"resolution\": %i,\n",dataSource[deviceId].ChanMode[chanNo]);
			printf ("         \"live\": %f,\n",chanLve[chanNo]);
			printf ("         \"min\": %f,\n",chanMin[chanNo]);
			printf ("         \"avg\": %f,\n",chanAvg[chanNo]);
			printf ("         \"max\": %f\n",chanMax[chanNo]);
			if (chanNo <8) { printf ("      },\n"); } else  { printf ("      }\n"); }			
		}
			
	}

	if (displayType == CPUREAD)
	{		

		//deviceId,deviceType,modbusId,ChanMode[1],chanLve[1],chanMin[1],chanAvg[1],chanMax[1].....ChanMode[8],chanLve[8],chanMin[8],chanAvg[8],chanMax[8]
		printf("%i,%i,%i,8,%i,%f,%f,%f,%f,%i,%f,%f,%f,%f,%i,%f,%f,%f,%f,%i,%f,%f,%f,%f,%i,%f,%f,%f,%f,%i,%f,%f,%f,%f,%i,%f,%f,%f,%f,%i,%f,%f,%f,%f;\n",
		                    deviceId,dataSource[deviceId].deviceType,dataSource[deviceId].modbusId,
							dataSource[deviceId].ChanMode[1],chanLve[1],chanMin[1],chanAvg[1],chanMax[1],	
							dataSource[deviceId].ChanMode[2],chanLve[2],chanMin[2],chanAvg[2],chanMax[2],
							dataSource[deviceId].ChanMode[3],chanLve[3],chanMin[3],chanAvg[3],chanMax[3],
							dataSource[deviceId].ChanMode[4],chanLve[4],chanMin[4],chanAvg[4],chanMax[4],	
							dataSource[deviceId].ChanMode[5],chanLve[5],chanMin[5],chanAvg[5],chanMax[5],
							dataSource[deviceId].ChanMode[6],chanLve[6],chanMin[6],chanAvg[6],chanMax[6],
							dataSource[deviceId].ChanMode[7],chanLve[7],chanMin[7],chanAvg[7],chanMax[7],	
							dataSource[deviceId].ChanMode[8],chanLve[8],chanMin[8],chanAvg[8],chanMax[8] );

	}
	
}


void decodeAdcModbusReadings(int deviceId)
{
	
	int regId;

	// Work our way through the list and diretly amend the values stored in 
	// dataSource[deviceId].value[x] based on the ADC resolution setting
	for(regId=1 ; regId<(dataSource[deviceId].numRegisters+1) ; regId++)
	{	
		// Deals with chan 1 value registers
		if (   dataSource[deviceId].regAddress[regId] == 1 
			|| dataSource[deviceId].regAddress[regId] == 17 
			|| dataSource[deviceId].regAddress[regId] == 33 
			|| dataSource[deviceId].regAddress[regId] == 49 )
		{	
				/*  Scale value based on resolution setting for chan
						Resolution 	Scaler
						12Bit		0.001
						14Bit		0.00025
						16Bit		0.0000625
						18Bit		0.000015625
				*/
			switch (dataSource[deviceId].ChanMode[1])
			{
				default:
				case 0: // [0] - 16bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.0000625);								
						break;
				case 1: // [0] - 12bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.001);								
						break;
				case 2: // [0] - 14bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.00025);								
						break;
				case 3: // [0] - 16bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.0000625);								
						break;
				case 4: // [0] - 18bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.000015625);								
						break;
			}
		}		

		// Deals with chan 2 value registers
		if (   dataSource[deviceId].regAddress[regId] == 3 
			|| dataSource[deviceId].regAddress[regId] == 19 
			|| dataSource[deviceId].regAddress[regId] == 35 
			|| dataSource[deviceId].regAddress[regId] == 51 )
		{	
			/*  Scale value based on resolution setting for chan
					Resolution 	Scaler
					12Bit		0.001
					14Bit		0.00025
					16Bit		0.0000625
					18Bit		0.000015625
			*/
			switch (dataSource[deviceId].ChanMode[2])
			{
				default:
				case 0: // [0] - 16bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.0000625);								
						break;
				case 1: // [0] - 12bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.001);								
						break;
				case 2: // [0] - 14bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.00025);								
						break;
				case 3: // [0] - 16bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.0000625);								
						break;
				case 4: // [0] - 18bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.000015625);								
						break;
			}
		}		

		// Deals with chan 3 value registers
		if (   dataSource[deviceId].regAddress[regId] == 5 
			|| dataSource[deviceId].regAddress[regId] == 21 
			|| dataSource[deviceId].regAddress[regId] == 37 
			|| dataSource[deviceId].regAddress[regId] == 53 )
		{	
			/*  Scale value based on resolution setting for chan
					Resolution 	Scaler
					12Bit		0.001
					14Bit		0.00025
					16Bit		0.0000625
					18Bit		0.000015625
			*/
			switch (dataSource[deviceId].ChanMode[3])
			{
				default:
				case 0: // [0] - 16bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.0000625);								
						break;
				case 1: // [0] - 12bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.001);								
						break;
				case 2: // [0] - 14bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.00025);								
						break;
				case 3: // [0] - 16bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.0000625);								
						break;
				case 4: // [0] - 18bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.000015625);								
						break;
			}
		}		

		// Deals with chan 4 value registers
		if (   dataSource[deviceId].regAddress[regId] == 7 
			|| dataSource[deviceId].regAddress[regId] == 23 
			|| dataSource[deviceId].regAddress[regId] == 39 
			|| dataSource[deviceId].regAddress[regId] == 55 )
		{	
			/*  Scale value based on resolution setting for chan
					Resolution 	Scaler
					12Bit		0.001
					14Bit		0.00025
					16Bit		0.0000625
					18Bit		0.000015625
			*/
			switch (dataSource[deviceId].ChanMode[4])
			{
				default:
				case 0: // [0] - 16bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.0000625);								
						break;
				case 1: // [0] - 12bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.001);								
						break;
				case 2: // [0] - 14bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.00025);								
						break;
				case 3: // [0] - 16bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.0000625);								
						break;
				case 4: // [0] - 18bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.000015625);								
						break;
			}
		}		


		// Deals with chan 5 value registers
		if (   dataSource[deviceId].regAddress[regId] == 9 
			|| dataSource[deviceId].regAddress[regId] == 25 
			|| dataSource[deviceId].regAddress[regId] == 41 
			|| dataSource[deviceId].regAddress[regId] == 57 )
		{	
			/*  Scale value based on resolution setting for chan
					Resolution 	Scaler
					12Bit		0.001
					14Bit		0.00025
					16Bit		0.0000625
					18Bit		0.000015625
			*/
			switch (dataSource[deviceId].ChanMode[5])
			{
				default:
				case 0: // [0] - 16bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.0000625);								
						break;
				case 1: // [0] - 12bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.001);								
						break;
				case 2: // [0] - 14bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.00025);								
						break;
				case 3: // [0] - 16bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.0000625);								
						break;
				case 4: // [0] - 18bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.000015625);								
						break;
			}
		}		


		// Deals with chan 6 value registers
		if (   dataSource[deviceId].regAddress[regId] == 11 
			|| dataSource[deviceId].regAddress[regId] == 27 
			|| dataSource[deviceId].regAddress[regId] == 43 
			|| dataSource[deviceId].regAddress[regId] == 59 )
		{	
			/*  Scale value based on resolution setting for chan
					Resolution 	Scaler
					12Bit		0.001
					14Bit		0.00025
					16Bit		0.0000625
					18Bit		0.000015625
			*/
			switch (dataSource[deviceId].ChanMode[6])
			{
				default:
				case 0: // [0] - 16bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.0000625);								
						break;
				case 1: // [0] - 12bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.001);								
						break;
				case 2: // [0] - 14bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.00025);								
						break;
				case 3: // [0] - 16bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.0000625);								
						break;
				case 4: // [0] - 18bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.000015625);								
						break;
			}
		}		

		// Deals with chan 7 value registers
		if (   dataSource[deviceId].regAddress[regId] == 13 
			|| dataSource[deviceId].regAddress[regId] == 29 
			|| dataSource[deviceId].regAddress[regId] == 45 
			|| dataSource[deviceId].regAddress[regId] == 61 )
		{	
			/*  Scale value based on resolution setting for chan
					Resolution 	Scaler
					12Bit		0.001
					14Bit		0.00025
					16Bit		0.0000625
					18Bit		0.000015625
			*/
			switch (dataSource[deviceId].ChanMode[7])
			{
				default:
				case 0: // [0] - 16bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.0000625);								
						break;
				case 1: // [0] - 12bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.001);								
						break;
				case 2: // [0] - 14bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.00025);								
						break;
				case 3: // [0] - 16bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.0000625);								
						break;
				case 4: // [0] - 18bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.000015625);								
						break;
			}
		}		

		// Deals with chan 8 value registers
		if (   dataSource[deviceId].regAddress[regId] == 15 
			|| dataSource[deviceId].regAddress[regId] == 31 
			|| dataSource[deviceId].regAddress[regId] == 47 
			|| dataSource[deviceId].regAddress[regId] == 63 )
		{	
			/*  Scale value based on resolution setting for chan
					Resolution 	Scaler
					12Bit		0.001
					14Bit		0.00025
					16Bit		0.0000625
					18Bit		0.000015625
			*/
			switch (dataSource[deviceId].ChanMode[8])
			{
				default:
				case 0: // [0] - 16bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.0000625);								
						break;
				case 1: // [0] - 12bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.001);								
						break;
				case 2: // [0] - 14bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.00025);								
						break;
				case 3: // [0] - 16bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.0000625);								
						break;
				case 4: // [0] - 18bit
						dataSource[deviceId].value[regId]  = (dataSource[deviceId].value[regId]*0.000015625);								
						break;
			}
		}		
		
	} // Main loop
		
} // Function



// Uses modbus_write_registers (FC16) to write single config registers 
int reconfigureADC(int deviceId, int adcAverageSetting, int modbusBaudSetting,  int chanResSetting[])
{  

	int rc;	
	int regId;
	const char *adcRes[5];
				adcRes[0] = "16Bit";
				adcRes[1] = "12Bit";
				adcRes[2] = "14Bit";
				adcRes[3] = "16Bit";
				adcRes[4] = "18Bit";

	const char *adcAvg[4];
				adcAvg[0] = "8 Readings";
				adcAvg[1] = "4 Readings";
				adcAvg[2] = "8 Readings";
				adcAvg[3] = "16 Readings";

	const char *adcBaud[6];
				adcBaud[0] = "19200";
				adcBaud[1] = "9600";
				adcBaud[2] = "14400";
				adcBaud[3] = "19200";
				adcBaud[4] = "38400";
				adcBaud[5] = "57600";



	uint16_t tableRegisters[1]; // 1 element array for use with modbus write command 

	// modbus device handle
	modbus_t *mb;  
	
	// Defines storage for returned registers from modbus read, *must* equal or exceed maximum number of registers requested, ask me how I know...
	uint16_t mbdata_UI16[30]; 


	

	printf("Processing Config Changes...\n");	

	mb = modbus_new_rtu( dataSource[deviceId].interface, 
					 	 dataSource[deviceId].baudRate,
						 dataSource[deviceId].parity[0],
						 dataSource[deviceId].dataBits,
						 dataSource[deviceId].stopBit);
						
	modbus_set_slave(mb, dataSource[deviceId].modbusId);


	// Set per-byte and total timeouts, this format has changed from the older libmodbus version.		
	// This could be useful if we've a latent RF-Link 
	// TODO : Don't hard code this, allow it to be configurable
	modbus_set_response_timeout(mb, 5, (5*1000000));
	modbus_set_byte_timeout(mb,5,(5*1000000));

	
	// Enable/Disable Modbus debug
	modbus_set_debug(mb, FALSE);

	// check we can connect (not sure if this is relevant on serial modbus)
	if(modbus_connect(mb) == -1)
	{
		printf("Connect Failed to Modbus ID [%i] on [%s]\n", dataSource[deviceId].modbusId, 
															 dataSource[deviceId].interface);
		modbus_close(mb);
		modbus_free(mb);
		return -1;
	}


	// Due to the way modbus registers start at 1 and not 0, 64 = register address 65
	for (int i=1 ; i<9 ; i++)
	{
		 
		if (chanResSetting[i] >0)  
		{  
			printf("Changing ADC Chan %i Resolution to %s...\n",i,adcRes[chanResSetting[i]]);
			tableRegisters[0]=chanResSetting[i];
			rc = modbus_write_registers(mb, (63+i) ,  1, tableRegisters);
			if (rc == -1)
			{
				printf("Modbus request Fail : Device Address [%i] Start Address [%i] For [1] Registers \n",deviceId,(63+i) );
				modbus_close(mb);
				modbus_free(mb);
				exit(1);
			}				
		}
	}

	if (adcAverageSetting>0)	
	{	
		printf("Changing ADC Averaging to %s...\n",adcAvg[adcAverageSetting]);
		tableRegisters[0]=adcAverageSetting;
		rc = modbus_write_registers(mb, 72,  1, tableRegisters);
		if (rc == -1)
		{
			printf("Modbus request Fail : Device Address [%i] Start Address [72] For [1] Registers \n",deviceId);
			modbus_close(mb);
			modbus_free(mb);
			exit(1);
		}			
	}

	if (modbusBaudSetting>0)	
	{	
		printf("Changing RTU Baud Rate to %s...\n",adcBaud[modbusBaudSetting]);		
		tableRegisters[0]=modbusBaudSetting;
		rc = modbus_write_registers(mb, 73,  1, tableRegisters);
		if (rc == -1)
		{
			printf("Modbus request Fail : Device Address [%i] Start Address [73] For [1] Registers \n",deviceId);
			modbus_close(mb);
			modbus_free(mb);
			exit(1);
		}	

	}

    
	printf("Writing Config Register...\n");	
	tableRegisters[0]=255;
	rc = modbus_write_registers(mb, 74,  1, tableRegisters);

	if (rc == -1)
	{
		printf("Modbus request Fail : Device Address [%i] Start Address [74] For [1] Registers \n",deviceId);
		modbus_close(mb);
		modbus_free(mb);
		exit(1);
	}	

	exit(0);

}


// Read back the channel config from the RTU device, in this case it's the ADC channel bit resolution setting
int getChanConfig(modbus_t *mb, int deviceId)
{
	// Defines storage for returned registers from modbus read, *must* equal or exceed maximum number of registers requested.
	uint16_t mbdata_UI16[30]; 

	int rc;	

	// Get RTU-AI8 specific channel config registers
	rc = modbus_read_registers(mb, 64, 8, mbdata_UI16);		
	if (rc == -1)
	{
		printf("Modbus request Fail : Device Address [%i] Start Address [64] For [8] Registers \n",deviceId);
		modbus_close(mb);
		modbus_free(mb);
		exit(1);
	}	

	dataSource[deviceId].ChanMode[1] = mbdata_UI16[0];
	dataSource[deviceId].ChanMode[2] = mbdata_UI16[1];
	dataSource[deviceId].ChanMode[3] = mbdata_UI16[2];
	dataSource[deviceId].ChanMode[4] = mbdata_UI16[3];
	dataSource[deviceId].ChanMode[5] = mbdata_UI16[4];
	dataSource[deviceId].ChanMode[6] = mbdata_UI16[5];
	dataSource[deviceId].ChanMode[7] = mbdata_UI16[6];
	dataSource[deviceId].ChanMode[8] = mbdata_UI16[7];

	return 0;
}


// Uses modbus_write_registers (FC16) to reset min readings to max value so current reading is always below it
int resetMinReadings(int deviceId) 
{  

	int rc;	
	int regId;


	uint16_t tableRegisters[16] = {32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767};

	// modbus device handle
	modbus_t *mb;  
	
	// Defines storage for returned registers from modbus read, *must* equal or exceed maximum number of registers requested, ask me how I know...
	uint16_t mbdata_UI16[30]; 

	
	mb = modbus_new_rtu( dataSource[deviceId].interface, 
					 	 dataSource[deviceId].baudRate,
						 dataSource[deviceId].parity[0],
						 dataSource[deviceId].dataBits,
						 dataSource[deviceId].stopBit);
						
	modbus_set_slave(mb, dataSource[deviceId].modbusId);


	// Set per-byte and total timeouts, this format has changed from the older libmodbus version.		
	// This could be useful if we've a latent RF-Link 
	// TODO : Don't hard code this, allow it to be configurable
	modbus_set_response_timeout(mb, 5, (5*1000000));
	modbus_set_byte_timeout(mb,5,(5*1000000));

	
	// Enable/Disable Modbus debug
	modbus_set_debug(mb, FALSE);

	// check we can connect (not sure if this is relevant on serial modbus)
	if(modbus_connect(mb) == -1)
	{
		printf("Connect Failed to Modbus ID [%i] on [%s]\n", dataSource[deviceId].modbusId, 
															 dataSource[deviceId].interface);
		modbus_close(mb);
		modbus_free(mb);
		return -1;
	}

	
	printf("Restting Min Counters...\r\n");
	// remember that modbus registers index from 0 so address 40001 = 0th register
	rc = modbus_write_registers(mb, 48,  16, tableRegisters);
	if (rc == -1)
	{
		printf("Modbus request Fail : Device Address [%i] Start Address [48] For [16] Registers \n",deviceId);
		modbus_close(mb);
		modbus_free(mb);
		exit(1);
	}			

	
	exit(0);

}


// Uses modbus_write_registers (FC16) to reset max readings to 0 so current values always exceeds it
int resetMaxReadings(int deviceId) 
{  

	int rc;	
	int regId;


	uint16_t tableRegisters[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 

	// modbus device handle
	modbus_t *mb;  
	
	// Defines storage for returned registers from modbus read, *must* equal or exceed maximum number of registers requested, ask me how I know...
	uint16_t mbdata_UI16[30]; 

	
	mb = modbus_new_rtu( dataSource[deviceId].interface, 
					 	 dataSource[deviceId].baudRate,
						 dataSource[deviceId].parity[0],
						 dataSource[deviceId].dataBits,
						 dataSource[deviceId].stopBit);
						
	modbus_set_slave(mb, dataSource[deviceId].modbusId);


	// Set per-byte and total timeouts, this format has changed from the older libmodbus version.		
	// This could be useful if we've a latent RF-Link 
	// TODO : Don't hard code this, allow it to be configurable
	modbus_set_response_timeout(mb, 5, (5*1000000));
	modbus_set_byte_timeout(mb,5,(5*1000000));

	
	// Enable/Disable Modbus debug
	modbus_set_debug(mb, FALSE);

	// check we can connect (not sure if this is relevant on serial modbus)
	if(modbus_connect(mb) == -1)
	{
		printf("Connect Failed to Modbus ID [%i] on [%s]\n", dataSource[deviceId].modbusId, 
															 dataSource[deviceId].interface);
		modbus_close(mb);
		modbus_free(mb);
		return -1;
	}

	
	printf("Restting Max Counters...\n\r");
	// remember that modbus registers index from 0 so address 40001 = 0th register
	rc = modbus_write_registers(mb, 32,  16, tableRegisters);
	if (rc == -1)
	{
		printf("Modbus request Fail : Device Address [%i] Start Address [72] For [1] Registers \n",deviceId);
		modbus_close(mb);
		modbus_free(mb);
		exit(1);
	}			
	
	exit(0);

}


