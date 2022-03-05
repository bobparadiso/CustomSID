#include <Arduino.h>
#include <stdlib.h>
#include "Terminal.h"
#include "Trace.h"

#define CMD_BUF_SIZE 64

char cmdBuf[CMD_BUF_SIZE];
char cmdBufIdx = 0;
char prevCmdBuf[CMD_BUF_SIZE] = {0};

//#define SERIAL_PORT Serial
#define SERIAL_PORT Serial1

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
	SERIAL_PORT.print("\x08 \x08");
	cmdBufIdx--;
}

//
void processSerialChar(char c)
{		
	//handle some escape sequences
	if (c == '\x1B')
	{
		//SERIAL_PORT.print("ESC");
		//safeDelay(100);
		if (SERIAL_PORT.available() >= 2)
		{
			char c1 = SERIAL_PORT.read();
			char c2 = SERIAL_PORT.read();
			if (c1 == '[' && c2 == 'A') //up; previous cmd
			{
				while (cmdBufIdx)
					doBackspace();
				strcpy(cmdBuf, prevCmdBuf);
				cmdBufIdx = strlen(cmdBuf);
				SERIAL_PORT.print(cmdBuf);
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
	
	SERIAL_PORT.write(c); //local echo
	
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
	while (SERIAL_PORT.available())
	{
		char c = SERIAL_PORT.read();
		processSerialChar(c);
	}
}
