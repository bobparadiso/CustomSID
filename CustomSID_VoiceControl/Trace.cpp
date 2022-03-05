// headers
#include <Arduino.h>
#include "Trace.h"

// buffer sizes
#define maxTraceF 128
#define maxFlashStr 128

#define SERIAL_PORT Serial
//#define SERIAL_PORT Serial1

char fshBuf[maxFlashStr];
char trcBuf[maxTraceF];

// debug output
void tracef(const __FlashStringHelper *fmt, ... )
{
  strcpy_P(fshBuf, (const char *)fmt);

  va_list args;
  va_start (args, fmt );
  vsnprintf(trcBuf, maxTraceF, fshBuf, args);
  va_end (args);
  trace(trcBuf);
}

// debug output
void tracef(const char *fmt, ... )
{
  //include printf family float support for ARM
  asm(".global _printf_float");

  va_list args;
  va_start (args, fmt );
  vsnprintf(trcBuf, maxTraceF, fmt, args);
  va_end (args);
  trace(trcBuf);
}

// debug output
void trace(const __FlashStringHelper *str)
{
  strcpy_P(fshBuf, (const char *)str);
  trace(fshBuf);
}

// debug output
void trace(const char *str)
{
  SERIAL_PORT.print(str);
}

