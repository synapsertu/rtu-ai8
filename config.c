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
*/
int readConfig()
{	
	int deviceId=1; // there's only one device configured in this tool
	int regId;
    
	//***************************************************************
	//********************** CONFIG *********************************
	//***************************************************************
	
	config.dsTotal=1; // there's only one device configured in this tool	

	//***************************************************************
	//********************** DATA SOURCES ***************************
	//***************************************************************	

   	dataSource[deviceId].deviceType  = RTU_AI8;

    // These values will be overwrtten by cmd line options
	dataSource[deviceId].modbusId    = 1;
	dataSource[deviceId].baudRate    = 19200;
	dataSource[deviceId].dataBits    = 8;		
	strcpy(dataSource[deviceId].parity,"None");
	dataSource[deviceId].stopBit     = 1;
	dataSource[deviceId].timeout     = 5;
	strcpy(dataSource[deviceId].interface, "/dev/ttyUSB0");
	
	
	// ChanMode is the resultion setting on the AI8 module, 

	dataSource[deviceId].ChanMode[1] = 0;  // 0/3 = 16Bit  	1 = 12Bit  	2 = 14Bit 	4 = 18Bit
	dataSource[deviceId].ChanMode[2] = 0; 
	dataSource[deviceId].ChanMode[3] = 0; 
	dataSource[deviceId].ChanMode[4] = 0; 
	dataSource[deviceId].ChanMode[5] = 0; 
	dataSource[deviceId].ChanMode[6] = 0; 
	dataSource[deviceId].ChanMode[7] = 0; 
	dataSource[deviceId].ChanMode[8] = 0; 

	
	// this MUST equal the total number of registered configured 
	dataSource[deviceId].numRegisters=31;


	//***************************************************************
	//********************** DATA POINTS ****************************
	//***************************************************************
	
	dataSource[deviceId].regAddress[1] =1   ;	dataSource[deviceId].regType[1]	 =3  ;		// ADC Channel 1 Live Reading  (32bit integer big endian)
	dataSource[deviceId].regAddress[2] =3   ;	dataSource[deviceId].regType[2]	 =3  ;		// ADC Channel 2 Live Reading  (32bit integer big endian)
	dataSource[deviceId].regAddress[3] =5   ;	dataSource[deviceId].regType[3]	 =3  ;		// ADC Channel 3 Live Reading  (32bit integer big endian)		
	dataSource[deviceId].regAddress[4] =7   ;	dataSource[deviceId].regType[4]	 =3  ;		// ADC Channel 4 Live Reading  (32bit integer big endian)
	dataSource[deviceId].regAddress[5] =9   ;	dataSource[deviceId].regType[5]	 =3  ;		// ADC Channel 5 Live Reading  (32bit integer big endian)
	dataSource[deviceId].regAddress[6] =11  ;	dataSource[deviceId].regType[6]	 =3  ;		// ADC Channel 6 Live Reading  (32bit integer big endian)
	dataSource[deviceId].regAddress[7] =13  ;	dataSource[deviceId].regType[7]	 =3  ;		// ADC Channel 7 Live Reading  (32bit integer big endian)
	dataSource[deviceId].regAddress[8] =15  ;	dataSource[deviceId].regType[8]	 =3  ;		// ADC Channel 8 Live Reading  (32bit integer big endian)

	dataSource[deviceId].regAddress[9] =17  ;	dataSource[deviceId].regType[9]	 =3  ;		// ADC Channel 1 Average Reading  (32bit integer big endian)
	dataSource[deviceId].regAddress[10] =19 ;	dataSource[deviceId].regType[10] =3  ;		// ADC Channel 2 Average Reading  (32bit integer big endian)
	dataSource[deviceId].regAddress[11] =21 ;	dataSource[deviceId].regType[11] =3  ;		// ADC Channel 3 Average Reading  (32bit integer big endian)
	dataSource[deviceId].regAddress[12] =23 ;	dataSource[deviceId].regType[12] =3  ;		// ADC Channel 4 Average Reading  (32bit integer big endian)
	dataSource[deviceId].regAddress[13] =25 ;	dataSource[deviceId].regType[13] =3  ;		// ADC Channel 5 Average Reading  (32bit integer big endian)
	dataSource[deviceId].regAddress[14] =27 ;	dataSource[deviceId].regType[14] =3  ;		// ADC Channel 6 Average Reading  (32bit integer big endian)
	dataSource[deviceId].regAddress[15] =29 ;	dataSource[deviceId].regType[15] =3  ;		// ADC Channel 7 Average Reading  (32bit integer big endian)
	dataSource[deviceId].regAddress[16] =31 ;	dataSource[deviceId].regType[16] =3  ;		// ADC Channel 8 Average Reading  (32bit integer big endian)

	dataSource[deviceId].regAddress[17] =33 ;	dataSource[deviceId].regType[17] =3  ;		// ADC Channel 1 Maximum Reading  (32bit integer big endian)	
	dataSource[deviceId].regAddress[18] =35 ;	dataSource[deviceId].regType[18] =3  ;		// ADC Channel 2 Maximum Reading  (32bit integer big endian)	
	dataSource[deviceId].regAddress[19] =37 ;	dataSource[deviceId].regType[19] =3  ;		// ADC Channel 3 Maximum Reading  (32bit integer big endian)	
	dataSource[deviceId].regAddress[20] =39 ;	dataSource[deviceId].regType[20] =3  ;		// ADC Channel 4 Maximum Reading  (32bit integer big endian)	
	dataSource[deviceId].regAddress[21] =41 ;	dataSource[deviceId].regType[21] =3  ;		// ADC Channel 5 Maximum Reading  (32bit integer big endian)	
	dataSource[deviceId].regAddress[22] =43 ;	dataSource[deviceId].regType[22] =3  ;		// ADC Channel 6 Maximum Reading  (32bit integer big endian)	
	dataSource[deviceId].regAddress[23] =45 ;	dataSource[deviceId].regType[23] =3  ;		// ADC Channel 7 Maximum Reading  (32bit integer big endian)	
	dataSource[deviceId].regAddress[24] =47 ;	dataSource[deviceId].regType[24] =3  ;		// ADC Channel 8 Maximum Reading  (32bit integer big endian)	

	dataSource[deviceId].regAddress[25] =49 ;	dataSource[deviceId].regType[25] =3  ;		// ADC Channel 1 Minimum Reading  (32bit integer big endian)	
	dataSource[deviceId].regAddress[26] =51 ;	dataSource[deviceId].regType[26] =3  ;		// ADC Channel 2 Minimum Reading  (32bit integer big endian)	
	dataSource[deviceId].regAddress[27] =53 ;	dataSource[deviceId].regType[27] =3  ;		// ADC Channel 3 Minimum Reading  (32bit integer big endian)	
	dataSource[deviceId].regAddress[28] =55 ;	dataSource[deviceId].regType[28] =3  ;		// ADC Channel 4 Minimum Reading  (32bit integer big endian)	
	dataSource[deviceId].regAddress[29] =57 ;	dataSource[deviceId].regType[29] =3  ;		// ADC Channel 5 Minimum Reading  (32bit integer big endian)	
	dataSource[deviceId].regAddress[30] =59 ;	dataSource[deviceId].regType[30] =3  ;		// ADC Channel 6 Minimum Reading  (32bit integer big endian)	
	dataSource[deviceId].regAddress[31] =61 ;	dataSource[deviceId].regType[31] =3  ;		// ADC Channel 7 Minimum Reading  (32bit integer big endian)	

}

void printConfig()
{
	int deviceId;
	int regId;
	
	printf("--------- Config Imported ----------\n\n");

	// i = device  n = register
   for(deviceId=1 ; deviceId<(config.dsTotal+1) ; deviceId++)
   {	
	
		printf("dataSource [%i] deviceType  = [%i]  \n", deviceId, dataSource[deviceId].deviceType);
		printf("dataSource [%i] modbusId    = [%i]  \n", deviceId, dataSource[deviceId].modbusId);
		printf("dataSource [%i] interface   = [%s]  \n", deviceId, dataSource[deviceId].interface);
		printf("dataSource [%i] baudRate    = [%i]  \n", deviceId, dataSource[deviceId].baudRate);
		printf("dataSource [%i] dataBits    = [%i]  \n", deviceId, dataSource[deviceId].dataBits);
		printf("dataSource [%i] parity      = [%s]  \n", deviceId, dataSource[deviceId].parity);	
		printf("dataSource [%i] stopBit     = [%i]  \n", deviceId, dataSource[deviceId].stopBit);
		printf("dataSource [%i] timeout     = [%i]  \n", deviceId, dataSource[deviceId].timeout);
		printf("dataSource [%i] DataPoints  = [%i] \n",  deviceId, dataSource[deviceId].numRegisters);
		printf("dataSource [%i] Chan 1 Mode = [%i] \n",  deviceId, dataSource[deviceId].ChanMode[1]);
		printf("dataSource [%i] Chan 2 Mode = [%i] \n",  deviceId, dataSource[deviceId].ChanMode[2]);
		printf("dataSource [%i] Chan 3 Mode = [%i] \n",  deviceId, dataSource[deviceId].ChanMode[3]);
		printf("dataSource [%i] Chan 4 Mode = [%i] \n",  deviceId, dataSource[deviceId].ChanMode[4]);
		printf("dataSource [%i] Chan 5 Mode = [%i] \n",  deviceId, dataSource[deviceId].ChanMode[5]);
		printf("dataSource [%i] Chan 6 Mode = [%i] \n",  deviceId, dataSource[deviceId].ChanMode[6]);
		printf("dataSource [%i] Chan 7 Mode = [%i] \n",  deviceId, dataSource[deviceId].ChanMode[7]);
		printf("dataSource [%i] Chan 8 Mode = [%i] \n",  deviceId, dataSource[deviceId].ChanMode[8]);
		
		for(regId=1 ; regId<(dataSource[deviceId].numRegisters+1) ; regId++)
		{	
			printf("[%i]\tregAddress  = [%i]  regType     = [%i]    ",regId, dataSource[deviceId].regAddress[regId],dataSource[deviceId].regType[regId]);
			printf("\n");
		}
		
	}
	printf("\n");
	printf("------------------------------------\n");
	printf("\n");
	
}