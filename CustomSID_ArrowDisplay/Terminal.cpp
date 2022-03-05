#include <Arduino.h>
#include <stdlib.h>
#include "Terminal.h"
#include "Trace.h"

#define CMD_BUF_SIZE 64

char cmdBuf[CMD_BUF_SIZE];
char cmdBufIdx = 0;
char prevCmdBuf[CMD_BUF_SIZE] = {0};

//defined in app specific code
void terminalCmdHandler(char *cmd);

//
void processTerminalCmd(char *cmdStr)
{
	trace("\r\n"); //go to next line
	
	char *cmd = strtok(cmdStr, " \r\n");
	if (cmd)
		terminalCmdHandler(cmd);
		
	trace(":"); //show next prompt
}

//
void doBackspace()
{
	Serial.print("\x08 \x08");
	cmdBufIdx--;
}

//
void processSerialChar()
{		
	char c = Serial.read();
	//Serial.println((uint8_t)c);

	//handle some escape sequences
	if (c == '\x1B')
	{
		//Serial.print("ESC");
		//delay(100);
		if (Serial.available() >= 2)
		{
			char c1 = Serial.read();
			char c2 = Serial.read();
			if (c1 == '[' && c2 == 'A') //up; previous cmd
			{
				while (cmdBufIdx)
					doBackspace();
				strcpy(cmdBuf, prevCmdBuf);
				cmdBufIdx = strlen(cmdBuf);
				Serial.print(cmdBuf);
			}				
		}
		
		return;
	}
	
	if (!(
		(c >= 'a' && c <= 'z') ||
		(c >= 'A' && c <= 'Z') ||
		(c >= '0' && c <= '9') ||
		strchr(" _.-\r\n\x08\\/!@#$%^&*()<>+=,?[]", c)
	))
		return;
		
	if (c == '\x08')
	{
		if (cmdBufIdx > 0)
			doBackspace();
		return;
	}

	if (cmdBufIdx == CMD_BUF_SIZE - 1)
		return;
	
	Serial.write(c); //local echo
	
	if (c == '\r' || c == '\n')
	{
		cmdBuf[cmdBufIdx++] = 0; //null-terminate
		strcpy(prevCmdBuf, cmdBuf);
		processTerminalCmd(cmdBuf);
		cmdBufIdx = 0;
		return;
	}
	cmdBuf[cmdBufIdx++] = c;
}

//
void processSerial()
{
	//tracef("processSerial: %d\r\n", millis());
	while (Serial.available())
		processSerialChar();
}
