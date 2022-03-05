#include <Arduino.h>
#include <stdlib.h>
#include "wiring_private.h" // pinPeripheral() function

#include "display.h"
#include "trace.h"

#define DISPLAY_RX 7 //not actually using, will use for SD card instead
#define DISPLAY_TX 6

//NOTE: commented out Serial5 and SERCOM5_Handler lines from:
//C:\Users\bobparadiso\AppData\Local\Arduino15\packages\adafruit\hardware\samd\1.2.3\variants\feather_m0\variant.cpp 
Uart Serial2 (&sercom5, DISPLAY_RX, DISPLAY_TX, SERCOM_RX_PAD_3, UART_TX_PAD_2);
 
void SERCOM5_Handler()
{
  Serial2.IrqHandler();
}

//
void sendDisplayCommand(char *cmd)
{
	//tracef("sendDisplayCommand: %s\r\n", cmd);
	Serial2.print(cmd);
}

//
void sendDisplayDirection(uint8_t direction, uint8_t active)
{
	char *lights[] = {LIGHT_FWD, LIGHT_LT, LIGHT_RT, LIGHT_REV, LIGHT_VLT, LIGHT_VRT};

	char cmd[4];
	sprintf(cmd, "%s%d", lights[direction], active);
	sendDisplayCommand(cmd);
}

//
void sendDisplayBrightness(uint8_t brightness)
{
	char cmd[5];
	sprintf(cmd, "B%03d", brightness);
	sendDisplayCommand(cmd);
}

//
void setupDisplay()
{
	Serial2.begin(9600);

	//assign pins SERCOM
	//pinPeripheral(DISPLAY_RX, PIO_SERCOM); //SD card instead
	pinPeripheral(DISPLAY_TX, PIO_SERCOM);
}
